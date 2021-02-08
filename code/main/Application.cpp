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
#include "Application.hpp"
#include "raylib.h"

Application::Application()
    : m_scale(0)
    , m_width(0)
    , m_height(0)
    , m_fullscreen(false)
    , m_show_map(false)
    , m_title("")
    , m_running(false)
    , m_show_fps(false)
    , m_should_exit(false)
{}

Application::~Application()
{
}

bool Application::init(const std::string title, int width, int height, float scale, const bool fullscreen)
{
    m_width = width;
    m_height = height;
    m_scale = scale;
    m_title = title;
    m_fullscreen = fullscreen;

    InitWindow(m_width * m_scale, m_height * m_scale, m_title.c_str());
    SetTargetFPS(60);

    return true;
}

void Application::run()
{
    m_running = true;

    if (!OnUserCreate()) m_running = false;

    while (!WindowShouldClose() && m_running )
    {
        event();

        OnUserUpdate(1.0);

        render();
    }
    OnUserDestroy();
    CloseWindow();
}

void Application::event()
{
}

void Application::render()
{
    OnUserRender();
}
