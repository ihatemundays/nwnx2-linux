/*
 *  NWNeXalt - Empty File
 *  (c) 2007 Doug Swarin (zac@intertex.net)
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
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 *  $Id$
 *  $HeadURL$
 *
 */

#ifndef _NX_SAFE_H_
#define _NX_SAFE_H_

#ifdef __cplusplus
extern "C" {
#endif

void *nx_safe_calloc(size_t, size_t);
void *nx_safe_malloc(size_t);
void *nx_safe_realloc(void *, size_t);

void nx_safe_free(void *);

char *nx_safe_strdup(const char *);

#ifdef __cplusplus
}
#endif

#endif /* _NX_SAFE_H_ */

/* vim: set sw=4: */
