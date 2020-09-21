#include "client/game_window.hpp"

int main()
{
    auto win = q::client::create_window("Q");
    q::client::game_window game{win};

    game.run_loop();

    return 0;
}

