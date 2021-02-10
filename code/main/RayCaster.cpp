/*# This file is part of the
# ██████╗ ███████╗██████╗ ███╗   ███╗ █████╗ ██████╗ ██╗      ██████╗  ██████╗ ██████╗ ████████╗
# ██╔══██╗██╔════╝██╔══██╗████╗ ████║██╔══██╗██╔══██╗██║      ██╔══██╗██╔═══██╗██╔══██╗╚══██╔══╝
# ██████╔╝█████╗  ██████╔╝██╔████╔██║███████║██║  ██║██║█████╗██████╔╝██║   ██║██████╔╝   ██║   
# ██╔═══╝ ██╔══╝  ██╔══██╗██║╚██╔╝██║██╔══██║██║  ██║██║╚════╝██╔═══╝ ██║   ██║██╔══██╗   ██║   
# ██║     ███████╗██║  ██║██║ ╚═╝ ██║██║  ██║██████╔╝██║      ██║     ╚██████╔╝██║  ██║   ██║   
# ╚═╝     ╚══════╝╚═╝  ╚═╝╚═╝     ╚═╝╚═╝  ╚═╝╚═════╝ ╚═╝      ╚═╝      ╚═════╝ ╚═╝  ╚═╝   ╚═╝   
#   project
#
#   https://github.com/jacmoe/permadi-port
#
#   (c) 2021 Jacob Moena
#
#   Zlib License
#*/
#include "RayCaster.hpp"
#include <cmath>

double RayCaster::arc2rad(double angle)
{
    return (angle * 3.14159) / m_angle180;
}

void RayCaster::init(int width, int height)
{
    m_tile_size = 64;
    m_wall_height = 64;
    m_projection_plane_width = width;
    m_projection_plane_height = height;

    m_angle60 = m_projection_plane_width;

    m_angle30 = static_cast<int>(m_angle60/2);
    m_angle15 = static_cast<int>(m_angle30/2);
    m_angle90 = static_cast<int>(m_angle30*3);
    m_angle180 = static_cast<int>(m_angle90*2);
    m_angle270 = static_cast<int>(m_angle90*3);
    m_angle360 = static_cast<int>(m_angle60*6);
    m_angle0 = 0;
    m_angle5 = static_cast<int>(m_angle30/6);
    m_angle10 = static_cast<int>(m_angle5*2);
    m_angle45 = static_cast<int>(m_angle15*3);

    m_player_x = 100;
    m_player_y = 160;
    m_player_arc = m_angle5 + m_angle5;
    m_player_dist_to_proj_plane = 277;
    m_player_height = 32;
    m_player_speed = 16;

    m_proj_plane_y_center = height / 2;

    // m_player_map_x;
    // m_player_map_y;
    // m_minimap_width;

    m_map_width = 12;
    m_map_height = 12;

    // m_anim_frame_id;

    m_f_sin_table.assign(m_angle360 + 1, 0);
    m_i_sin_table.assign(m_angle360 + 1, 0);
    m_f_cos_table.assign(m_angle360 + 1, 0);
    m_i_cos_table.assign(m_angle360 + 1, 0);
    m_f_tan_table.assign(m_angle360 + 1, 0);
    m_i_tan_table.assign(m_angle360 + 1, 0);
    m_f_fish_table.assign(m_angle360 + 1, 0);
    m_f_xstep_table.assign(m_angle360 + 1, 0);
    m_f_ystep_table.assign(m_angle360 + 1, 0);

    double radian;
    for(int i = 0; i <= m_angle360; i++)
    {
        // Populate tables with their radian values.
        // (The addition of 0.0001 is a kludge to avoid divisions by 0. Removing it will produce unwanted holes in the wall when a ray is at 0, 90, 180, or 270 degree angles)
        radian = arc2rad(i) + 0.0001;

        m_f_sin_table[i] = std::sin(radian);
        m_i_sin_table[i] = 1.0 / m_f_sin_table[i];
        m_f_cos_table[i] = std::cos(radian);
        m_i_cos_table[i] = 1.0 / m_f_cos_table[i];
        m_f_tan_table[i] = std::tan(radian);
        m_i_tan_table[i] = 1.0 / m_f_tan_table[i];

        // Next we crate a table to speed up wall lookups.
        // 
        //  You can see that the distance between walls are the same
        //  if we know the angle
        //  _____|_/next xi______________
        //       |
        //  ____/|next xi_________   slope = tan = height / dist between xi's
        //     / |
        //  __/__|_________  dist between xi = height/tan where height=tile size
        // old xi|
        //                  distance between xi = x_step[view_angle];

        // facing left
        if(i >= m_angle90 && i < m_angle270)
        {
            m_f_xstep_table[i] = m_tile_size / m_f_tan_table[i];
            if(m_f_xstep_table[i] > 0)
            {
                m_f_xstep_table[i] = -m_f_xstep_table[i];
            }
        }
        // facing right
        else
        {
            m_f_xstep_table[i] = m_tile_size / m_f_tan_table[i];
            if(m_f_xstep_table[i] < 0)
            {
                m_f_xstep_table[i] = -m_f_xstep_table[i];
            }
        }

        // facing down
        if(i >= m_angle0 && i < m_angle180)
        {
            m_f_ystep_table[i] = m_tile_size * m_f_tan_table[i];
            if(m_f_ystep_table[i] < 0)
            {
                m_f_ystep_table[i] = -m_f_ystep_table[i];
            }
        }
        // facing up
        else
        {
            m_f_ystep_table[i] = m_tile_size * m_f_tan_table[i];
            if(m_f_ystep_table[i] > 0)
            {
                m_f_ystep_table[i] = -m_f_ystep_table[i];
            }
        }
    }

    // Create table for fixing fishbowl distortion
    for (int i = m_angle30; i < m_angle30; i++)
    {
        radian = arc2rad(i);
        // we don't have negative angle, so make it start at 0
        // this will give range from column 0 to 319
        m_f_fish_table[i + m_angle30] = 1.0 / std::cos(radian);
    }
}
