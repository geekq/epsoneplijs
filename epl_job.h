/**
 * Copyright (c) 2003 Hin-Tak Leung
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
**/

#define EPL_VERSION "0.2"

#include <stdio.h>
#include "epl_compress.h" 

/* job_info is created as a simplier version of
   ParamList which can be used by the header/etc routes
   without passing along string parameters */


typedef struct _EPL_job_info EPL_job_info; 

struct _EPL_job_info {
  FILE *outfile;
  int model;
  int paper_size_mm_h;
  int paper_size_mm_v;
  int dpi_h;
  int dpi_v;
  int ritech;
  int toner_save;
  int density;
  int pixel_h;
  int pixel_v;
};

#define MODEL_UNKNOWN 0
#define MODEL_5700L   1
#define MODEL_5800L   2
#define MODEL_5900L   3

static char *printername[]={
  "<unknown>",
  "EPL-5700L",
  "EPL-5800L",
  "EPL-5900L"
};

#define EPL_JOB_STARTED_YES 1
#define EPL_JOB_STARTED_NO  2

int epl_job_header(EPL_job_info *epl_job_info);

int epl_page_header(EPL_job_info *epl_job_info);

int epl_print_stripe(EPL_job_info *epl_job_info, typ_stream *stream);

int epl_page_footer(EPL_job_info *epl_job_info);

int epl_job_footer(EPL_job_info *epl_job_info);

#undef EPL_DEBUG

#ifdef EPL_DEBUG
#define VERBOSE
#endif