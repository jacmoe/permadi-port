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
#include <string>

class Application
{
public:
    Application();
    virtual ~Application();

    bool init(const std::string title, int width, int height, float scale = 1.0f, const bool fullscreen = false);
    void run();

protected:
    virtual bool OnUserCreate() { return true; }
    virtual bool OnUserUpdate(double fDeltaTime) { return true; }
    virtual bool OnUserRender() { return true; }
    virtual bool OnUserDestroy() { return  true; }

    float m_scale;
    int m_width;
    int m_height;
    bool m_fullscreen;
    bool m_show_map;
    bool m_show_fps;
    float m_average_fps;

private:
    std::string m_title;
    bool m_running;
    bool m_should_exit;

    void event();
    void render();
};
