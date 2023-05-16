# kiss-xorg

```ascii
+----------------------------------------+
|                           ;;;;;;;;;;;;;|
| XORG                      ;\;;;\\;;;|;;|
|                            ;\\;;|;|;;|||
|                             ;'| '    ;||
|         .---.                 | | |   ||
|;;;     [     ]   |||    ;;@   | | '   ||
|@;@;;   |  X  | `-vvv  ;@;;;;_/    |   \|
|;;;@;;@ |     |    | ;;;;;;@/   /;;\    |
+----------------------------------------+
```

A collection of repositories for running Xorg on KISS Linux.

Due to upstream KISS making the switch to wayland, and
my reliance on X, I forked the main repo.

Feel free to create Issues and Pull Requests for outdated software!

## Structure

* `xorg/`  - contains the X11 distribution, and other misc software for X
* `extra/` - contains the browser (firefox) and media player (mpv)
	* NOTE: You will still need the upstream extra repo!
* `community/` - contains useful software that depends on X
	* currently working on saving some of the software that was dropped from [kiss-community/community](https://github.com/kiss-community/community)
* `games/` - contains video games
* `xfce4/` - contains the XFCE4 desktop environment
* `kde1/` - contains the KDE desktop, version 1

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

## What's that extra file? (esources)

Since VERSION markers have officially been removed in upstream kiss (as of
this PR: https://codeberg.org/kiss-community/kiss/pulls/121 ), `esources` is
a way to continue using the previously valid version markers.

This does require having access to an additional command, namely
`kiss-echecksum` which is available from my personal repo
[here](https://raw.githubusercontent.com/ehawkvu/kiss-personal/master/bin/kiss-echecksum).

If there is sufficient interest, and no purity spiraling from upstream, I would
not mind trying to contribute this utility to the `contrib/` folder for kiss.

Bumping versions then has this workflow:

```shell
echo "9.99.9 1" > version
kiss echecksum
```

## Support

distro/fork | tested? | notes
-----------:|--------:|-----:
[kisslinux](https://kisslinux.org) | Y | n/a
[gkisslinux](https://github.com/kiss-community/grepo) | Y |
[glasnost](https://glasnost.org) | Y | clang is a dep of some packages, so a dummy package is needed
[wyverkiss](https://github.com/wyvertux) | Y | need to fork some packages for gmake & bison
[noir](https://github.com/noirlinux/main) | N |
[carbslinux](https://carbslinux.org/) | n/a | carbs ships with Xorg already
