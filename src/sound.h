/*
 * Copyright (C) 2004-2008 Kim Woelders
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies of the Software, its documentation and marketing & publicity
 * materials, and acknowledgment shall be given in the documentation, materials
 * and software packages that this Software was used.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */
#ifndef _SOUND_H_
#define _SOUND_H_

typedef struct {
   unsigned int        channels;
   unsigned int        bit_per_sample;
   unsigned int        rate;
   void               *data;
   unsigned int        size;	/* N. bytes in data */
} SoundSampleData;

typedef struct _sample Sample;

typedef struct {
   int                 (*Init) (void);
   void                (*Exit) (void);
   Sample             *(*SampleLoad) (const char *file);
   void                (*SampleDestroy) (Sample * s);
   void                (*SamplePlay) (Sample * s);
} SoundOps;

int                 SoundSampleGetData(const char *file, SoundSampleData * ssd);

#endif /* _SOUND_H_ */