/*
 *  Copyright (C) 2014 Jolla Ltd.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 as
 *  published by the Free Software Foundation.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */
#ifndef __PROVXMLPARSER_H
#define __PROVXMLPARSER_H

#ifdef __cplusplus
extern "C" {
#endif

struct provisioning_data {
	struct internet *internet;
//	GSList *w2;
	struct w2 *w2;
/* There might be others but lets assume for now that only one mms context */
//	GSList *w4;
	struct w4 *w4;
};
struct internet {
	char *name;
	char *apn;
	char *username;
	char *password;
};
struct w2 {
	char *name;
	char *apn;
	char *username;
	char *password;
//	char *protocol; notsure if this needed
};

struct w4 {
	char *name;
	char *apn;
	char *username;
	char *password;
//	char *protocol; notsure if this needed
	char *messageproxy;
	char *messagecenter;
	char *portnro;
};

void *get_provisioning_data();

int parse_xml_main(const char *document,int length);

void clean_provisioning_data();

#ifdef __cplusplus
}
#endif

#endif /* __PROVXMLPARSER_H */
