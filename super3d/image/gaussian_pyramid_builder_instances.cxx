/*ckwg +29
 * Copyright 2010-2015 by Kitware, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *  * Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 *  * Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 *  * Neither name of Kitware, Inc. nor the names of any contributors may be used
 *    to endorse or promote products derived from this software without specific
 *    prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ``AS IS''
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "gaussian_pyramid_builder.txx"

#define GAUSSIAN_PYRAMID_INSTANTIATE(PixType)                                \
template void                                                                \
super3d::gaussian_pyramid_builder::                                            \
build_pyramid<PixType >(const vil_image_view<PixType >&,                     \
                       std::vector<vil_image_view<PixType > >&) const;        \
template void                                                                \
super3d::tile_pyramid<PixType >(const std::vector<vil_image_view<PixType > > &, \
                             vil_image_view<PixType > &)

#define GAUSSIAN_PYRAMID_INSTANTIATE2(PixType, GradType)                     \
template void                                                                \
super3d::gaussian_pyramid_builder::                                            \
build_pyramid<PixType, GradType >(const vil_image_view<PixType >&,           \
                                 std::vector<vil_image_view<PixType > >&,     \
                                 std::vector<vil_image_view<GradType > >&) const

GAUSSIAN_PYRAMID_INSTANTIATE(float);
GAUSSIAN_PYRAMID_INSTANTIATE(double);
GAUSSIAN_PYRAMID_INSTANTIATE(vxl_byte);
GAUSSIAN_PYRAMID_INSTANTIATE(vxl_uint_16);

GAUSSIAN_PYRAMID_INSTANTIATE2(float, float);
GAUSSIAN_PYRAMID_INSTANTIATE2(double, double);
GAUSSIAN_PYRAMID_INSTANTIATE2(vxl_byte, double);
GAUSSIAN_PYRAMID_INSTANTIATE2(vxl_uint_16, double);