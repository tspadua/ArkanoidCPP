#pragma once

class StateManager {
    public:
        State state;

        enum State { Play, Menu }

        StateManager();

        void setState(State _state);
}