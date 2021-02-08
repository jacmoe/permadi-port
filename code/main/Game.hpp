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

#include "Application.hpp"

class Game : public Application
{
public:
    Game();
    ~Game();

protected:
    bool OnUserCreate() override;
    bool OnUserUpdate(double deltaTime) override;
    bool OnUserRender() override;
    bool OnUserDestroy() override;
};
