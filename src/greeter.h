/*
 * Copyright (C) 2010 Robert Ancell.
 * Author: Robert Ancell <robert.ancell@canonical.com>
 * 
 * This program is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option) any later
 * version. See http://www.gnu.org/copyleft/gpl.html the full text of the
 * license.
 */

#ifndef _GREETER_H_
#define _GREETER_H_

#include "session.h"
#include "pam-session.h"

G_BEGIN_DECLS

#define GREETER_TYPE (greeter_get_type())
#define GREETER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), GREETER_TYPE, Greeter))

typedef struct GreeterPrivate GreeterPrivate;

typedef struct
{
    Session         parent_instance;
    GreeterPrivate *priv;
} Greeter;

typedef struct
{
    SessionClass parent_class;
    void (*login)(Greeter *greeter, const gchar *username, const gchar *session, const gchar *language);
    void (*quit)(Greeter *greeter);
} GreeterClass;

GType greeter_get_type (void);

Greeter *greeter_new (void);

void greeter_set_default_user (Greeter *greeter, const gchar *username, gint timeout);

void greeter_set_theme (Greeter *greeter, const gchar *theme);

void greeter_set_layout (Greeter *greeter, const gchar *layout);

const gchar *greeter_get_layout (Greeter *greeter);

void greeter_set_session (Greeter *greeter, const gchar *session);

const gchar *greeter_get_session (Greeter *greeter);

PAMSession *greeter_get_pam_session (Greeter *greeter);

void greeter_quit (Greeter *greeter);

G_END_DECLS

#endif /* _GREETER_H_ */