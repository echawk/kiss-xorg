# tinyx

tinyx is an alternative to xorg-server, and provides an X server that uses
the framebuffer.

## Usage

Make sure you have 'sx' installed:

`kiss b sx`

Now we need to copy the script to make some edits:

`cp $KISS_ROOT/usr/bin/sx .`

Now run the following command to make sx work with tinyx:

`sed -i 's/Xorg/Xfbdev/;s/-keeptty//' sx`

### Adding Fonts

If you want to add a font to tinyx here are the steps:

1. Get the font in .bdf format.
2. Use mkfontscale(1) to convert them into a format that X can read.
  1. Optionally compress resulting font with gzip.
3. Give the font an alias that other X programs can understand.[1]
  1. For example, tinyx looks for 2 fonts at startup, aliased "fixed" &
     "cursor.
4. Run 'exec mkfontscale -b -s -l' in the font directory to generate fonts.dir

[1] - The font alias is only required if the font name patches the alias
      perfectly.
