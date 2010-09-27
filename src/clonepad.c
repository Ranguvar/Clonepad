/*
 * Copyright (c) 2010
 * 	Devin Cofer <ranguvar@archlinux.us>
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include <gtk/gtk.h>

#include <stdlib.h>

int
main (int argc, char *argv[])
{
	GtkWidget *window;
	GtkWidget *label;

	gtk_init(&argc, &argv);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "Clonepad");

	/*
	 * Connect the destroy signal of the window to gtk_main_quit
	 * When the window is about to be destroyed, we get a notification and
	 * stop the main GTK+ loop.
	 */
	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

	label = gtk_label_new("hello, world");
	gtk_container_add(GTK_CONTAINER(window), label);

	gtk_widget_show_all(window);
	/* main loop, execution stays here until program is closed */
	gtk_main();

	return EXIT_SUCCESS;
}
