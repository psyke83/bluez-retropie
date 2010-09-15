/*
 *
 *  BlueZ - Bluetooth protocol stack for Linux
 *
 *  Copyright (C) 2010 GSyC/LibreSoft, Universidad Rey Juan Carlos.
 *  Authors:
 *  Santiago Carot Nemesio <sancane at gmail.com>
 *  Jose Antonio Santos-Cadenas <santoscadenas at gmail.com>
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
 *  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */


#ifndef __HDP_TYPES_H__
#define __HDP_TYPES_H__

#define HDP_UUID		"00001400-0000-1000-8000-00805F9B34FB"
#define HDP_SOURCE_UUID		"00001401-0000-1000-8000-00805F9B34FB"
#define HDP_SINK_UUID		"00001402-0000-1000-8000-00805F9B34FB"

#define MANAGER_PATH		"/org/bluez"

#define HEALTH_MANAGER		"org.bluez.HealthManager"

#define HDP_VERSION		0x0100

#define HDP_SERVICE_NAME	"Bluez HDP"
#define HDP_SERVICE_DSC		"A Bluez health device profile implementation"
#define HDP_SERVICE_PROVIDER	"Bluez"

#define HDP_MDEP_ECHO		0x00
#define HDP_MDEP_INITIAL	0x01
#define HDP_MDEP_FINAL		0x7F

#define HDP_ERROR		g_quark_from_static_string("hdp-error-quark")

#define HDP_NO_PREFERENCE_DC	0x00
#define HDP_RELIABLE_DC		0x01
#define HDP_STREAMING_DC	0x02

#define HDP_SINK_ROLE_AS_STRING		"sink"
#define HDP_SOURCE_ROLE_AS_STRING	"source"

typedef enum {
	HDP_SOURCE = 0x00,
	HDP_SINK = 0x01
} HdpRole;

typedef enum {
	HDP_DIC_PARSE_ERROR,
	HDP_DIC_ENTRY_PARSE_ERROR,
	HDP_UNSPECIFIED_ERROR,
	HDP_UNKNOWN_ERROR
} HdpError;

enum data_specs {
	DATA_EXCHANGE_SPEC_11073 = 0x01
};

struct hdp_application {
	char			*path;		/* The path of the application */
	uint16_t		data_type;	/* Data type handled for this application */
	gboolean		data_type_set;	/* Flag for dictionary parsing */
	uint8_t			role;		/* Role of this application */
	gboolean		role_set;	/* Flag for dictionary parsing */
	char			*description;	/* Options description for SDP record */
	uint8_t			id;		/* The identification is also the mdepid */
	char			*oname;		/* Name of the owner application */
};

struct hdp_adapter {
	struct btd_adapter	*btd_adapter;	/* Bluetooth adapter */
	struct mcap_instance	*mi;		/* Mcap instance in */
	uint16_t		ccpsm;		/* Control channel psm */
	uint16_t		dcpsm;		/* Data channel psm */
	uint32_t		sdp_handler;	/* SDP record handler */
	uint32_t		record_state;	/* Service record state */
};

#endif /* __HDP_TYPES_H__ */
