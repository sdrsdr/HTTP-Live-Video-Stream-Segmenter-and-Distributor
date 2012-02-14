/*
 * Copyright (c) 2009 Chase Douglas
 * Copyright (c) 2012 Stoian Ivanov
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License version 2
 * as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

/**********************************************************************************
 * This code is part of HTTP-Live-Video-Stream-Segmenter-and-Distributor
 * look for newer versions at github.com
 **********************************************************************************/

#include <stdio.h>


#include "segmenter.h"
#include "libavformat/avformat.h"

void debugReturnCode(int r) {
	if (verbosity<AV_LOG_INFO) return;
    switch (r) {
#if USE_OLD_FFMPEG
        case AVERROR_UNKNOWN:
#else
        case AVERROR(EINVAL):
#endif
            fprintf(stderr, "DEBUG: Unknown error.\n");
            break;
#if USE_OLD_FFMPEG
        case AVERROR_IO:
#else
        case AVERROR(EIO):
#endif             
            fprintf(stderr, "DEBUG:I/O error.\n");
            break;
#if USE_OLD_FFMPEG
        case AVERROR_NUMEXPECTED:
#else
        case AVERROR(EDOM):
#endif			    
            fprintf(stderr, "DEBUG:Number syntax expected in filename.\n");
            break;
        case AVERROR_INVALIDDATA:
            fprintf(stderr, "DEBUG:Invalid data found.\n");
            break;
#if USE_OLD_FFMPEG
        case AVERROR_NOMEM:
#else
        case AVERROR(ENOMEM):
#endif        
            fprintf(stderr, "DEBUG:Not enough memory.\n");
            break;
#if USE_OLD_FFMPEG
        case AVERROR_NOFMT:
#else
        case AVERROR(EILSEQ):
#endif         
            fprintf(stderr, "DEBUG:Unknown format.\n");
            break;
#if USE_OLD_FFMPEG
        case AVERROR_NOTSUPP:
#else
        case AVERROR(ENOSYS):
#endif       
            fprintf(stderr, "DEBUG:Operation not supported.\n");
            break;
#if USE_OLD_FFMPEG
        case AVERROR_NOENT:
#else
        case AVERROR(ENOENT):
#endif        
            fprintf(stderr, "DEBUG:No such file or directory.\n");
            break;
        case AVERROR_EOF:
            fprintf(stderr, "DEBUG:End of file.\n");
            break;
        case AVERROR_PATCHWELCOME:
            fprintf(stderr, "DEBUG:Not yet implemented in FFmpeg. Patches welcome.\n");
            break;
#if USE_OLD_FFMPEG
            /**< Codes For Old FFMPEG Deprecated. */
#else
        case AVERROR_BUG:
            fprintf(stderr, "DEBUG:Internal bug. AVERROR_BUG\n");
            break;
        case AVERROR_BUG2:
            fprintf(stderr, "DEBUG:Internal bug. AVERROR_BUG2.\n");
            break;
        case AVERROR_STREAM_NOT_FOUND:
            fprintf(stderr, "DEBUG:Stream not found.\n");
            break;
        case AVERROR_PROTOCOL_NOT_FOUND:
            fprintf(stderr, "DEBUG:Protocol not found.\n");
            break;
        case AVERROR_OPTION_NOT_FOUND:
            fprintf(stderr, "DEBUG:Option not found.\n");
            break;
        case AVERROR_MUXER_NOT_FOUND:
            fprintf(stderr, "DEBUG:Muxer not found. \n");
            break;
        case AVERROR_FILTER_NOT_FOUND:
            fprintf(stderr, "DEBUG:Filter not found.\n");
            break;
        case AVERROR_EXIT:
            fprintf(stderr, "DEBUG:Immediate exit was requested; the called function should not be restarted.\n");
            break;
        case AVERROR_ENCODER_NOT_FOUND:
            fprintf(stderr, "DEBUG:Encoder not found.\n");
            break;
        case AVERROR_DEMUXER_NOT_FOUND:
            fprintf(stderr, "DEBUG:Demuxer not found.\n");
            break;
        case AVERROR_DECODER_NOT_FOUND:
            fprintf(stderr, "DEBUG:Decoder not found.\n");
            break;
        case AVERROR_BSF_NOT_FOUND:
            fprintf(stderr, "DEBUG:Bitstream filter not found.\n");
            break;
#endif	
        default:
            fprintf(stderr, "DEBUG:Unknown return code: %d\n", r);
    }
}