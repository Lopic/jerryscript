/* Copyright 2015 Samsung Electronics Co., Ltd.
 * Copyright 2015 University of Szeged.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef RE_PARSER_H
#define RE_PARSER_H

#ifndef CONFIG_ECMA_COMPACT_PROFILE_DISABLE_REGEXP_BUILTIN

#include "opcodes-dumper.h"

typedef uint8_t token_type_t;

#define RE_TOK_EOF                            0 /* EOF */
#define RE_TOK_BACKREFERENCE                  1 /* \[0..9] */
#define RE_TOK_CHAR                           2 /* any character */
#define RE_TOK_ALTERNATIVE                    3 /* | */
#define RE_TOK_ASSERT_START                   4 /* ^ */
#define RE_TOK_ASSERT_END                     5 /* $ */
#define RE_TOK_PERIOD                         6 /* . */
#define RE_TOK_START_CAPTURE_GROUP            7 /* ( */
#define RE_TOK_START_NON_CAPTURE_GROUP        8 /* (?: */
#define RE_TOK_END_GROUP                      9 /* ')' */
#define RE_TOK_ASSERT_START_POS_LOOKAHEAD    10 /* (?= */
#define RE_TOK_ASSERT_START_NEG_LOOKAHEAD    11 /* (?! */
#define RE_TOK_ASSERT_WORD_BOUNDARY          12 /* \b */
#define RE_TOK_ASSERT_NOT_WORD_BOUNDARY      13 /* \B */
#define RE_TOK_DIGIT                         14 /* \d */
#define RE_TOK_NOT_DIGIT                     15 /* \D */
#define RE_TOK_WHITE                         16 /* \s */
#define RE_TOK_NOT_WHITE                     17 /* \S */
#define RE_TOK_WORD_CHAR                     18 /* \w */
#define RE_TOK_NOT_WORD_CHAR                 19 /* \W */
#define RE_TOK_START_CHAR_CLASS              20 /* [ ] */
#define RE_TOK_START_INV_CHAR_CLASS          21 /* [^ ] */

#define RE_ITERATOR_INFINITE ((uint32_t)-1)
#define RE_MAX_RE_DECESC_DIGITS 9

/* FIXME: depends on unicode support */
#define RE_CHAR_UNDEF ((ecma_char_t)-1)

#define RE_CONTROL_CHAR_NUL  0x0000 /* \0 */
#define RE_CONTROL_CHAR_BEL  0x0008 /* \b */
#define RE_CONTROL_CHAR_TAB  0x0009 /* \t */
#define RE_CONTROL_CHAR_EOL  0x000a /* \n */
#define RE_CONTROL_CHAR_VT   0x000b /* \v */
#define RE_CONTROL_CHAR_FF   0x000c /* \f */
#define RE_CONTROL_CHAR_CR   0x000d /* \r */

typedef struct
{
  token_type_t type;
  uint32_t value;
  uint32_t qmin;
  uint32_t qmax;
  bool greedy;
} re_token_t;

typedef struct
{
  lit_utf8_byte_t *pattern_start_p;
  lit_utf8_byte_t *current_char_p;
  int num_of_groups;
  uint32_t num_of_classes;
} re_parser_ctx_t;

typedef void (*re_char_class_callback) (void *re_ctx_p, uint32_t start, uint32_t end);

ecma_completion_value_t
re_parse_char_class (re_parser_ctx_t *parser_ctx_p,
                     re_char_class_callback append_char_class,
                     void *re_ctx_p, re_token_t *out_token_p);

ecma_completion_value_t
re_parse_next_token (re_parser_ctx_t *parser_ctx_p, re_token_t *out_token_p);

#endif /* CONFIG_ECMA_COMPACT_PROFILE_DISABLE_REGEXP_BUILTIN */
#endif /* RE_PARSER_H */
