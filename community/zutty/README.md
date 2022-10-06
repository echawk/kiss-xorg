# zutty

zutty is a minimal terminal emulator written in C++

## configuration

By default, zutty doesn't work out of the box since it looks for a font with
the name '9x18' which *typically* doesn't exist. To fix this, a shell alias
or a wrapper script is required.

Example alias:

`alias ztty=zutty -font LiberationMono`
