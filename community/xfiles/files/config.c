#include <stddef.h>

#define THUMBSIZE       "64"
#define NCMDARGS        3
#define LEN(a)          (sizeof(a)/sizeof((a)[0]))

/*
 * First include the icon files.
 */
#include "icons/file-app.xpm"
#include "icons/file-archive.xpm"
#include "icons/file-audio.xpm"
#include "icons/file-code.xpm"
#include "icons/file-config.xpm"
#include "icons/file-gear.xpm"
#include "icons/file-image.xpm"
#include "icons/file-info.xpm"
#include "icons/file-object.xpm"
#include "icons/file-text.xpm"
#include "icons/file-video.xpm"
#include "icons/file.xpm"
#include "icons/folder-apps.xpm"
#include "icons/folder-book.xpm"
#include "icons/folder-code.xpm"
#include "icons/folder-db.xpm"
#include "icons/folder-download.xpm"
#include "icons/folder-game.xpm"
#include "icons/folder-gear.xpm"
#include "icons/folder-home.xpm"
#include "icons/folder-image.xpm"
#include "icons/folder-link.xpm"
#include "icons/folder-meme.xpm"
#include "icons/folder-mount.xpm"
#include "icons/folder-music.xpm"
#include "icons/folder-up.xpm"
#include "icons/folder-video.xpm"
#include "icons/folder.xpm"

static char *file_app[]     = { "fx", NULL };
static char *file_archive[] = { "f", "*.tar*", "*.t[bgx]z", "*.lzma", "*.lz", "*.zip", "*.rar", NULL };
static char *file_audio[]   = { "f", "*.mp[23]", "*.m4a", "*.m3u", "*.ogg", "*.opus", "*.flac", NULL };
static char *file_code[]    = { "f", "*.c", "*.cpp", "*.h", "*.go", "*.html", "*.css", "*.lua", "*.rs", "*.s", "*.*sh", "*.pl", "*.sed", "*.awk", NULL };
static char *file_config[]  = { "f", "*.conf", "*.config", "*.yaml", "*.toml", "*.xml", "*.ini", "*.json", "*rc", NULL };
static char *file_image[]   = { "f", "*.png", "*.gif", "*.p[bgp]m", "*.x[bp]m", "*.jpeg", "*.jpg", "*.jpe", "*.jfi", "*.jfi[f]", "*.svg", NULL };
static char *file_info[]    = { "f", "*.[1-9]", "*.scd", "*.3p", "README*", "COPYING*", "LICENSE*", "COPYRIGHT*", NULL };
static char *file_gear[]    = { "f", "[Mm]akefile", "configure", "meson.build", "CMakeLists.txt", NULL };
static char *file_object[]  = { "f", "*.o", "*.so", "*.a", "*.hex", "*.rom", NULL };
static char *file_text[]    = { "f", "*.epub", "*.txt", "*.ps", "*.eps", "*.djvu", "*.md", "*.org", "*.pdf", "*.csv", NULL };
static char *file_video[]   = { "f", "*.mp4", "*.webm", "*.mkv", "*.mov", "*.ogv", NULL };
static char *folder_apps[]  = { "d", "bin", NULL };
static char *folder_code[]  = { "d", "src", "[Pp]r*j", "[Dd]evelopment", NULL };
static char *folder_db[]    = { "d", "var", "~/.local", "~/.local/share", NULL };
static char *folder_book[]  = { "d", "man", "doc", "docs", "[Dd]ox", "[Dd]ocuments", NULL };
static char *folder_dl[]    = { "d", "tmp", "dl", "[Dd]ownloads", NULL };
static char *folder_game[]  = { "d", "games", "[Gg]ames", NULL };
static char *folder_image[] = { "d", "img", "[Pp]ix", "[Pp]ic*", "[Ii]mage*", NULL };
static char *folder_gear[]  = { "d", "etc", "~/.config", NULL };
static char *folder_meme[]  = { "d", "[Mm]emes", NULL };
static char *folder_mount[] = { "d", "mnt", "mount", "[Mm]edia", NULL };
static char *folder_music[] = { "d", "mus", "music", "[Mm]usic", NULL };
static char *folder_video[] = { "d", "vid", "[Vv]ideos", NULL };
static char *folder_home[]  = { "d", "~", NULL };
static char *folder_up[]    = { "d", "..", NULL };
static char *folder_link[]  = { "dl", NULL };
static char *folder[]       = { "d", NULL };

char **icons[][2] = {
	{ file_app,     file_app_xpm,        },
	{ file_archive, file_archive_xpm,    },
	{ file_audio,   file_audio_xpm,      },
	{ file_code,    file_code_xpm,       },
	{ file_config,  file_config_xpm,     },
	{ file_gear,    file_gear_xpm,       },
	{ file_image,   file_image_xpm,      },
	{ file_info,    file_info_xpm,       },
	{ file_object,  file_object_xpm,     },
	{ file_text,    file_text_xpm,       },
	{ file_video,   file_video_xpm,      },
	{ folder_up,    folder_up_xpm,       },
	{ folder_apps,  folder_apps_xpm,     },
	{ folder_code,  folder_code_xpm,     },
	{ folder_db,    folder_db_xpm,       },
	{ folder_book,  folder_book_xpm,     },
	{ folder_dl,    folder_download_xpm, },
	{ folder_game,  folder_game_xpm,     },
	{ folder_image, folder_image_xpm,    },
	{ folder_gear,  folder_gear_xpm,     },
	{ folder_home,  folder_home_xpm,     },
	{ folder_meme,  folder_meme_xpm,     },
	{ folder_mount, folder_mount_xpm,    },
	{ folder_music, folder_music_xpm,    },
	{ folder_video, folder_video_xpm,    },
	{ folder_link,  folder_link_xpm,     },
	{ folder,       folder_xpm,          },
	{ NULL,         file_xpm,            },
};
size_t nicons = LEN(icons);

static char *imagemagick[NCMDARGS] = {
	"/bin/sh", "-c",
	"convert \"${1}[0]\" -thumbnail \""THUMBSIZE"x"THUMBSIZE"\" " \
	"-define filename:literal=true \"${2}\"",
};

char **thumbs[][2] = {
	{ file_video,      imagemagick, },
	{ file_image,      imagemagick, },
	{ NULL,            NULL, },
};
