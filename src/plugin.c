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

#include <gtk/gtk.h>
#include <glib.h>
#include <sharing-plugin-interface.h>
#include <sharing-transfer.h>
#include <conicconnection.h>
#include <osso-log.h>

#include "send.h"

/**
 * sharing_plugin_interface_init:
 * @dead_mans_switch: What?
 *
 * Initialize interface
 *
 * Returns: 0
 */
guint sharing_plugin_interface_init (gboolean* dead_mans_switch)
{
    ULOG_DEBUG_L("sharing_manager_plugin_interface_init");
    return 0;
}

/**
 * sharing_plugin_interface_uninit:
 * @dead_mans_switch: What?
 *
 * Uninitialize interface
 *
 * Returns: 0
 */
guint sharing_plugin_interface_uninit (gboolean* dead_mans_switch)
{
    ULOG_DEBUG_L("sharing_manager_plugin_interface_uninit");
    return 0;
}

/**
 * sharing_plugin_interface_send:
 * @transfer: Transfer to be send
 * @con: Connection used
 * @dead_mans_switch: 
 *
 * Send interface.
 *
 * Returns: Result of send
 */
SharingPluginInterfaceSendResult sharing_plugin_interface_send
    (SharingTransfer* transfer, ConIcConnection* con,
    gboolean* dead_mans_switch)
{
    ULOG_DEBUG_L ("sharing_plugin_interface_send");
    SharingPluginInterfaceSendResult ret_val = SHARING_SEND_ERROR_UNKNOWN;
    ret_val = send_mms (transfer, con, dead_mans_switch);
    return ret_val;
}

/**
 * sharing_plugin_interface_account_setup:
 * @transfer: #SharingTransfer send
 * @service: #SharingService
 * @worked_on: Connection used
 * @osso_context_t: Osso context
 *
 * Send interface
 *
 * Returns: Result of account setup
 */
SharingPluginInterfaceAccountSetupResult sharing_plugin_interface_account_setup
    (GtkWindow* parent, SharingService* service, SharingAccount** worked_on,
    osso_context_t* osso)
{
    ULOG_DEBUG_L ("sharing_plugin_interface_account_setup");
    SharingPluginInterfaceAccountSetupResult ret = SHARING_ACCOUNT_SETUP_SUCCESS;;
    return ret;
}

/**
 * sharing_manager_plugin_interface_account_validate:
 * @account: Account tested
 * @con: Connection used to test account
 * @dead_mans_switch: 
 *
 * Validates account information.
 *
 * Returns: Result of account validation
 */
SharingPluginInterfaceAccountValidateResult
sharing_plugin_interface_account_validate (SharingAccount* account, 
    ConIcConnection* con, gboolean *cont, gboolean* dead_mans_switch)
{
    ULOG_DEBUG_L ("sharing_plugin_interface_account_validate");
    SharingPluginInterfaceAccountValidateResult ret_val = SHARING_ACCOUNT_VALIDATE_SUCCESS;
    //ret_val = validate (account, con, cont, dead_mans_switch);
    return ret_val;
}

/**
 * sharing_plugin_interface_edit_account:
 * @account: Account tested
 * @con: Connection used to test account
 * @dead_mans_switch: 
 *
 * Edit account plugin implementation.
 *
 * Returns: Result of account edit
 */
SharingPluginInterfaceEditAccountResult
    sharing_plugin_interface_edit_account (GtkWindow* parent,
    SharingAccount* account, ConIcConnection* con, gboolean* dead_mans_switch)
{
    SharingPluginInterfaceEditAccountResult ret = 0;
    ULOG_DEBUG_L ("sharing_plugin_interface_edit_account");
    return SHARING_EDIT_ACCOUNT_SUCCESS;
}

/**
 * test:
 * @account: #SharingAccount to be tested
 * @con: Connection used
 * @dead_mans_switch: Turn to %FALSE at least every 30 seconds.
 *
 * Test if #SharingAccount is valid.
 *
 * Returns: #SharingPluginInterfaceTestAccountResult
 */
SharingPluginInterfaceAccountValidateResult validate (SharingAccount* account,
    ConIcConnection* con, gboolean *cont, gboolean* dead_mans_switch)
{
    SharingPluginInterfaceAccountValidateResult ret =
        SHARING_ACCOUNT_VALIDATE_SUCCESS;
   

    return ret;
}

