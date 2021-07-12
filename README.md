# kiss-xorg

A collection of repositories for running Xorg on KISS Linux.

Due to upstream KISS making the switch to wayland, and
my reliance on X, I forked the main repo.

Feel free to create Issues and Pull Requests for outdated software!

## Structure

* `xorg/`  - contains the X11 distribution, and other misc software for X
* `extra/` - contains the browser (firefox) and media player (mpv)
	* NOTE: You will still need the upsteam extra repo!

## Usage

Just add the directories *before* the official KISS repos in your KISS_PATH

Example:

```sh
KISS_PATH="/path/to/repo/core"
KISS_PATH="${KISS_PATH}:/path/to/kiss-xorg/extra"
KISS_PATH="${KISS_PATH}:/path/to/kiss-xorg/xorg"
KISS_PATH="${KISS_PATH}:/path/to/repo/extra"
...
```
