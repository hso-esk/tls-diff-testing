#!/bin/bash

if [ -f __sessions ]; then
    SESSIONS=$(cat __sessions)
    for SESSION in $SESSIONS; do
        echo "Stopping session $SESSION"
        screen -X -S $SESSION quit
    done
    rm -f __sessions
else
    echo "No sessions to stop"
fi

