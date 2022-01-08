#!/bin/sh

# shellcheck disable=2086
exec /usr/lib/chromium/chromium \
    --enable-gpu-rasterization \
    $CHROME_FLAGS "$@"
