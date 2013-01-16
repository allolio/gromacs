/*
 * This file is part of the GROMACS molecular simulation package.
 *
 * Copyright (c) 2012,2013, by the GROMACS development team, led by
 * David van der Spoel, Berk Hess, Erik Lindahl, and including many
 * others, as listed in the AUTHORS file in the top-level source
 * directory and at http://www.gromacs.org.
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
#ifndef _gmx_x86_simd256_single_h_
#define _gmx_x86_simd256_single_h_

/* This file includes the highest possible level of x86 (math) acceleration */

#ifdef GMX_X86_AVX_256
#include "gmx_x86_avx_256.h"
#include "gmx_math_x86_avx_256_single.h"
#else
#ifdef GMX_X86_AVX_128_FMA
#include "gmx_x86_avx_128_fma.h"
#include "gmx_math_x86_avx_128_fma_single.h"
#else
#ifdef GMX_X86_SSE4_1
#include "gmx_x86_sse4_1.h"
#include "gmx_math_x86_sse4_1_single.h"
#else
#ifdef GMX_X86_SSE2
#include "gmx_x86_sse2.h"
#include "gmx_math_x86_sse2_single.h"
#else
#error No x86 acceleration defined
#endif
#endif
#endif
#endif


static inline __m128
gmx_mm_calc_rsq_ps(__m128 dx, __m128 dy, __m128 dz)
{
    return _mm_add_ps( _mm_add_ps( _mm_mul_ps(dx,dx), _mm_mul_ps(dy,dy) ), _mm_mul_ps(dz,dz) );
}

/* Normal sum of four __m128 registers */
#define gmx_mm_sum4_ps(t0,t1,t2,t3)  _mm_add_ps(_mm_add_ps(t0,t1),_mm_add_ps(t2,t3))

#ifdef GMX_X86_AVX_256

static inline __m256
gmx_mm256_calc_rsq_ps(__m256 dx, __m256 dy, __m256 dz)
{
    return _mm256_add_ps( _mm256_add_ps( _mm256_mul_ps(dx,dx), _mm256_mul_ps(dy,dy) ), _mm256_mul_ps(dz,dz) );
}

/* Normal sum of four __m256 registers */
#define gmx_mm256_sum4_ps(t0,t1,t2,t3)  _mm256_add_ps(_mm256_add_ps(t0,t1),_mm256_add_ps(t2,t3))

#endif

#endif /* _gmx_x86_simd256_single_h_ */
