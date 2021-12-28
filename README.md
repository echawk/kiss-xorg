# kiss-xorg

A collection of repositories for running Xorg on KISS Linux.

Due to upstream KISS making the switch to wayland, and
my reliance on X, I forked the main repo.

Feel free to create Issues and Pull Requests for outdated software!

## Structure

* `xorg/`  - contains the X11 distribution, and other misc software for X
* `extra/` - contains the browser (firefox) and media player (mpv)
	* NOTE: You will still need the upsteam extra repo!
* `community/` - contains useful software that depends on X
	* currently working on saving some of the software that was dropped from [kiss-community/community](https://github.com/kiss-community/community)

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

## Support

distro/fork | tested? | notes
-----------:|--------:|-----:
[kisslinux](https://kisslinux.org) | Y | n/a
[gkisslinux](https://github.com/gkisslinux) | Y |
[glasnost](https://glasnost.org) | N |
[wyverkiss](https://github.com/wyvertux) | Y | need to fork some packges for gmake & bison
