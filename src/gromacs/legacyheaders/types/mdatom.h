/*
 * This file is part of the GROMACS molecular simulation package.
 *
 * Copyright (c) 1991-2000, University of Groningen, The Netherlands.
 * Copyright (c) 2001-2004, The GROMACS development team.
 * Copyright (c) 2012,2013,2014, by the GROMACS development team, led by
 * Mark Abraham, David van der Spoel, Berk Hess, and Erik Lindahl,
 * and including many others, as listed in the AUTHORS file in the
 * top-level source directory and at http://www.gromacs.org.
 *
 * GROMACS is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License
 * as published by the Free Software Foundation; either version 2.1
 * of the License, or (at your option) any later version.
 *
 * GROMACS is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with GROMACS; if not, see
 * http://www.gnu.org/licenses, or write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA.
 *
 * If you want to redistribute modifications to GROMACS, please
 * consider that scientific software is very special. Version
 * control is crucial - bugs must be traceable. We will be happy to
 * consider code for inclusion in the official distribution, but
 * derived work must not be called official GROMACS. Details are found
 * in the README & COPYING files - if they are missing, get the
 * official version at http://www.gromacs.org.
 *
 * To help us fund GROMACS development, we humbly ask that you cite
 * the research papers on the package. Check out http://www.gromacs.org.
 */

#ifndef _mdatom_h
#define _mdatom_h

#include "gromacs/legacyheaders/types/simple.h"

#ifdef __cplusplus
extern "C" {
#endif


#define  NO_TF_TABLE 255
#define  DEFAULT_TF_TABLE 0

typedef struct {
    real                   tmassA, tmassB, tmass;
    int                    nr;
    int                    nalloc;
    int                    nenergrp;
    gmx_bool               bVCMgrps;
    int                    nPerturbed;
    int                    nMassPerturbed;
    int                    nChargePerturbed;
    int                    nTypePerturbed;
    gmx_bool               bOrires;
    real                  *massA, *massB, *massT, *invmass;
    real                  *chargeA, *chargeB;
    real                  *gaussian;
    real                  *sqrt_c6A, *sqrt_c6B;
    real                  *sigmaA, *sigmaB, *sigma3A, *sigma3B;
    gmx_bool              *bPerturbed;
    int                   *typeA, *typeB;
    unsigned short        *ptype;
    unsigned short        *cTC, *cENER, *cACC, *cFREEZE, *cVCM;
    unsigned short        *cU1, *cU2, *cORF;
    /* for QMMM, atomnumber contains atomic number of the atoms */
    gmx_bool              *bQM;
    /* The range of home atoms */
    int                    homenr;
    /* The lambda value used to create the contents of the struct */
    real                   lambda;
    /* The AdResS weighting function */
    real                  *wf;
    unsigned short        *tf_table_index; /* The tf table that will be applied, if thermodyn, force enabled*/
} t_mdatoms;

#ifdef __cplusplus
}
#endif


#endif
