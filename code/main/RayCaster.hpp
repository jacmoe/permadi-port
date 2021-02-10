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
#pragma once
#include <vector>

class RayCaster
{
public:
    RayCaster() = default;

    void init(int width, int height);

private:
    int m_tile_size;
    int m_wall_height;
    int m_projection_plane_width;
    int m_projection_plane_height;
    int m_angle0;
    int m_angle5;
    int m_angle10;
    int m_angle15;
    int m_angle30;
    int m_angle45;
    int m_angle60;
    int m_angle90;
    int m_angle180;
    int m_angle270;
    int m_angle360;

    std::vector<double> m_f_sin_table;
    std::vector<double> m_i_sin_table;
    std::vector<double> m_f_cos_table;
    std::vector<double> m_i_cos_table;
    std::vector<double> m_f_tan_table;
    std::vector<double> m_i_tan_table;
    std::vector<double> m_f_fish_table;
    std::vector<double> m_f_xstep_table;
    std::vector<double> m_f_ystep_table;

    int m_player_x;
    int m_player_y;
    int m_player_arc;
    int m_player_dist_to_proj_plane;
    int m_player_height;
    int m_player_speed;

    int m_proj_plane_y_center;
    int m_player_map_x;
    int m_player_map_y;
    int m_minimap_width;

    int m_map_width;
    int m_map_height;

    int m_anim_frame_id;

    double arc2rad(double angle);
};
