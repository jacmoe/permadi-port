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

    void init();

private:
    int m_tile_size;
    int m_wall_height;
    float m_projection_plane_width;
    float m_projection_plane_height;
    double m_angle0;
    double m_angle5;
    double m_angle10;
    double m_angle15;
    double m_angle30;
    double m_angle45;
    double m_angle60;
    double m_angle90;
    double m_angle180;
    double m_angle270;
    double m_angle360;

    std::vector<double> m_f_sin_table;
    std::vector<double> m_i_sin_table;
    std::vector<double> m_f_cos_table;
    std::vector<double> m_i_cos_table;
    std::vector<double> m_f_tan_table;
    std::vector<double> m_i_tan_table;
    std::vector<double> m_f_fish_table;
    std::vector<double> m_i_xstep_table;
    std::vector<double> m_i_ystep_table;

    int m_player_x;
    int m_player_y;
    double m_player_arc;
    float m_player_dist_to_proj_plane;
    float m_player_height;
    float m_player_speed;

    float m_proj_plane_y_center;
    int m_player_map_x;
    int m_player_map_y;
    int m_minimap_width;

    int m_map_width;
    int m_map_height;

    int m_anim_frame_id;
};