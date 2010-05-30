/*
 * This file is part of sharing-plugin-template
 *
 * Copyright (C) 2008-2009 Nokia Corporation. All rights reserved.
 *
 * This maemo code example is licensed under a MIT-style license,
 * that can be found in the file called "COPYING" in the root
 * directory.
 *
 */

#include <stdio.h>
#include <glib.h>
#include <osso-log.h>
#include "send.h"

#include <stdlib.h>
#include <glib.h>
#include <glib/gprintf.h>
#include <dbus/dbus-glib.h>

#define MMS_DBUS_NAME  "se.frals.fmms"
#define MMS_DBUS_IFACE "se.frals.fmms"
#define MMS_DBUS_PATH  "/se/frals/fmms"
#define MMS_SHARE_SIG  "send_via_service"

/**
 * send:
 * @account: #SharingTransfer to be send
 * @con: Connection used
 * @dead_mans_switch: Turn to %FALSE at least every 30 seconds.
 *
 * Sends #SharingTransfer to service.
 *
 * Returns: #SharingPluginInterfaceSendResult
 */
SharingPluginInterfaceSendResult send_mms (SharingTransfer* transfer,
    ConIcConnection* con, gboolean* dead_mans_switch)
{
    SharingPluginInterfaceSendResult ret = SHARING_SEND_SUCCESS;

    SharingEntry *entry = sharing_transfer_get_entry( transfer );

    gint result = 0;
    for (GSList* p = sharing_entry_get_media (entry); p != NULL; p = g_slist_next(p)) {
      SharingEntryMedia* media = p->data;
      /* Process media */
      if (!sharing_entry_media_get_sent (media)) {
	/* Post media */
	result = call_mms_dbus(media);
	/* Process post result */
	if (result == 0 /* EXAMPLE: MY_SEND_RESULT_SUCCESS */) {
	  /* If success mark media as sent */
	  sharing_entry_media_set_sent (media, TRUE);
	  /* And mark process to your internal data structure */
	  //my_send_task->upload_done += sharing_entry_media_get_size (media); 
	} else {
	  /* We have sent the file in last sharing-manager call */
	  //my_send_task->upload_done += sharing_entry_media_get_size (media);
	}
      }
    }
    return ret;
}

gint call_mms_dbus(SharingEntryMedia *media)
{
	GError *error = NULL;
	DBusGConnection *connection;

	g_type_init();

	connection = dbus_g_bus_get(DBUS_BUS_SESSION, &error);
	if (!connection)
	{
		g_printerr("Failed to open connection to system bus: %s\n", error->message);
		ULOG_DEBUG_L("Failed to open connection to system bus: %s\n", error->message);	
		g_clear_error(&error);
		return EXIT_FAILURE;
	}

	DBusGProxy *proxy;
	gint retval = 0;
	const gchar *local_file;
	const gchar *desc;
	const gchar *title;
	local_file = sharing_entry_media_get_localpath(media);
	desc = sharing_entry_media_get_desc(media);
	title = sharing_entry_media_get_title(media);

	proxy = dbus_g_proxy_new_for_name(connection, MMS_DBUS_NAME, MMS_DBUS_PATH, MMS_DBUS_IFACE);
	if (!dbus_g_proxy_call(proxy, MMS_SHARE_SIG, &error, G_TYPE_STRING, local_file, G_TYPE_STRING, title, G_TYPE_STRING, desc, G_TYPE_INVALID))
	{
		if (error->domain == DBUS_GERROR && error->code == DBUS_GERROR_REMOTE_EXCEPTION) {
			g_printerr("Caught remote method exception %s: %s", dbus_g_error_get_name(error), error->message);
			ULOG_DEBUG_L("Caught remote method exception %s: %s", dbus_g_error_get_name(error), error->message);
		} else {
			g_printerr("Failed to call method: %s\n", error->message);
			ULOG_DEBUG_L("Failed to call method: %s\n", error->message);
		}
		g_clear_error(&error);
	}
	g_object_unref(proxy);

	return retval;
}

