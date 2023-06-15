# kde1

## installation

This repo is for the KDE desktop environment, version 1.

The following packages are the bare minimum:

* `qt1-git`
* `kde1-kdelibs-git`
* `kde1-kdebase-git`

Add the following line to the relevant file based on how you start X.

```
exec startkde
```

* `sx` -> `~/.config/sx/sxrc`
* `xinit` -> `~/.xinitrc`

Now you can start KDE1.
