/*
 * Copyright (C) 1995-2008 University of Karlsruhe.  All right reserved.
 *
 * This file is part of libFirm.
 *
 * This file may be distributed and/or modified under the terms of the
 * GNU General Public License version 2 as published by the Free Software
 * Foundation and appearing in the file LICENSE.GPL included in the
 * packaging of this file.
 *
 * Licensees holding valid libFirm Professional Edition licenses may use
 * this file in accordance with the libFirm Commercial License.
 * Agreement provided with the Software.
 *
 * This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
 * WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE.
 */

/**
 * @file
 * @brief   Compute loop depth information for VFirm graphs.
 * @author  Olaf Liebe
 * @version $Id: $
 */

#ifndef FIRM_ANA_VF_DEPTH_H
#define FIRM_ANA_VF_DEPTH_H

#include <stdio.h>
#include "firm_types.h"

typedef struct vl_info vl_info;

/** Compute the loop depth information for the given irg. */
vl_info *vl_init(ir_graph *irg);

/** Free the loop depth information for the given tree. */
void vl_free(vl_info *vli);

/** Get the associated graph. */
ir_graph *vl_get_irg(vl_info *vli);

/** Get the loop depth of the given node. */
unsigned vl_node_get_depth(vl_info *vli, ir_node *irn);

/** Copies the loop depth (if available) from src to dst. */
void vl_node_copy_depth(vl_info *vli, ir_node *src, ir_node *dst);

/** Helper for exact_copy that also transfers the depth info. */
ir_node *vl_exact_copy(vl_info *vli, ir_node *irn);

/** Helper for exchange that also transfers the depth info. */
void vl_exchange(vl_info *vli, ir_node *ir_old, ir_node *ir_new);

/** Dumps loop depth analysis debug information to the specified file. */
void vl_dump(vl_info *vli, FILE* f);

#endif
