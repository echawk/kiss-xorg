#!/bin/sh

export LD_LIBRARY_PATH="$LD_LIBRARY_PATH:/usr/lib/firefox"
exec /usr/lib/firefox/firefox
