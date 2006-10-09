/*
 *  Copyright (C) 2005 Giuseppe Torelli - <colossus73@gmail.com>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Street #330, Boston, MA 02111-1307, USA.
 */

#ifndef __XARCHIVER_CALLBACK_H
#define __XARCHIVER_CALLBACK_H

#define _GNU_SOURCE
#include <string.h>

#define ISODCL(from, to) (to - from + 1)

#include <gtk/gtk.h>
#include <gdk/gdkkeysyms.h>
#include <glib/gstdio.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <time.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

#include "arj.h"
#include "deb.h"
#include "lha.h"
#include "iso.h"
#include "zip.h"
#include "rar.h"
#include "tar.h"
#include "7zip.h"
#include "bzip2.h"
#include "rpm.h"
#include "gzip.h"
#include "archive.h"
#include "extract_dialog.h"
#include "add_dialog.h"

void xa_append_rows ( XArchive *archive , unsigned short int nc );
short int response;
double content_size;
unsigned long long int file_size, file_offset;
gboolean done,full_path,overwrite,add_recurse;
Extract_dialog_data *extract_window;
Add_dialog_data *add_window;
GtkWidget *dialog , *textview, *scrollwin, *vbox, *OutputWindow , *view_window, *archive_properties_win;
GtkTextBuffer *textbuf , *viewtextbuf;
GtkTextIter enditer , start, end;
GtkTextIter viewenditer, viewstart, viewend;
GtkListStore *liststore;
gchar *ComboArchiveType, *destination_path;
GtkTreeModel *model;

void xa_new_archive (GtkMenuItem *menuitem, gpointer user_data);
void xa_open_archive (GtkMenuItem *menuitem, gpointer user_data );
void xa_test_archive (GtkMenuItem *menuitem, gpointer user_data);
void xa_close_archive (GtkMenuItem *menuitem, gpointer user_data);
void xa_quit_application (GtkMenuItem *menuitem, gpointer user_data);
void xa_delete_archive (GtkMenuItem *menuitem, gpointer user_data);
void xa_show_help (GtkMenuItem *menuitem, gpointer user_data);
void xa_about (GtkMenuItem *menuitem, gpointer user_data);
void on_options1_activate (GtkMenuItem *menuitem, gpointer user_data);
void xa_extract_archive ( GtkMenuItem *menuitem, gpointer user_data);
void xa_convert_sfx ( GtkMenuItem *menuitem, gpointer user_data);
void xa_select_all ( GtkMenuItem *menuitem, gpointer user_data);
void xa_deselect_all ( GtkMenuItem *menuitem, gpointer user_data);
void ShowShellOutput ( GtkMenuItem *menuitem );
void xa_iso_properties ( GtkMenuItem *menuitem , gpointer user_data );
void xa_archive_properties ( GtkMenuItem *menuitem , gpointer user_data );
void xa_view_file_inside_archive ( GtkMenuItem *menuitem , gpointer user_data );
void xa_cancel_archive ( GtkMenuItem *menuitem , gpointer user_data);
void xa_add_files_archive ( GtkMenuItem *menuitem, gpointer user_data );
void Activate_buttons();
void on_drag_data_received (GtkWidget *widget,GdkDragContext *context, int x,int y,GtkSelectionData *data, unsigned int info, unsigned int time, gpointer user_data);
void drag_begin (GtkWidget *treeview1,GdkDragContext *context, gpointer data);
void drag_end (GtkWidget *treeview1, GdkDragContext *context, gpointer data);
void drag_data_get (GtkWidget *widget, GdkDragContext *dc, GtkSelectionData *selection_data, guint info, guint t, gpointer data);

int ShowGtkMessageDialog ( GtkWindow *window, int mode,int type,int button, const gchar *message1,const gchar *message2);
int DetectArchiveType ( gchar *filename );

gboolean key_press_function ( GtkWidget* widget, GdkEventKey* event,gpointer data);
gboolean treeview_select_search (GtkTreeModel *model,gint column,const gchar *key,GtkTreeIter *iter,gpointer search_data);
gboolean isTar ( FILE *ptr );
gboolean isISO ( FILE *ptr );
gboolean isLha ( FILE *ptr );
gboolean xa_report_child_stderr (GIOChannel *ioc, GIOCondition cond, gpointer data);
gboolean DetectPasswordProtectedArchive ( int type , FILE *dummy_ptr, unsigned char magic[6]);

void RemoveColumnsListStore ();
void EmptyTextBuffer ();
void xa_create_liststore ( unsigned short int nc, gchar *columns_names[] , GType columns_types[]);
void ConcatenateFileNames (GtkTreeModel *model, GtkTreePath *treepath, GtkTreeIter *iter, GString *data);
void ConcatenateFileNames2 (gchar *filename , GString *data);
void xa_cat_filenames (GtkTreeModel *model, GtkTreePath *treepath, GtkTreeIter *iter, GString *data);
gboolean xa_run_command ( gchar *command , gboolean watch_child_flag );
void OffDeleteandViewButtons();
void OffTooltipPadlock();
void Update_StatusBar (gchar *msg);
void xa_watch_child ( GPid pid, gint status, gpointer data);
gchar *xa_open_file_dialog ();
void xa_activate_link (GtkAboutDialog *about, const gchar *link, gpointer data);
gchar *name;
gchar *permissions;
#endif

