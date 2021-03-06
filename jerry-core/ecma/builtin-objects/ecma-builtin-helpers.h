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

#ifndef ECMA_OBJECT_PROTOTYPE_H
#define ECMA_OBJECT_PROTOTYPE_H

#include "ecma-globals.h"

/** \addtogroup ecma ECMA
 * @{
 *
 * \addtogroup ecmabuiltinhelpers ECMA builtin helper operations
 * @{
 */

extern ecma_completion_value_t ecma_builtin_helper_object_to_string (const ecma_value_t this_arg);
extern ecma_completion_value_t ecma_builtin_helper_get_to_locale_string_at_index (ecma_object_t *obj_p, uint32_t index);
extern ecma_completion_value_t ecma_builtin_helper_object_get_properties (ecma_object_t *obj,
                                                                          bool only_enumerable_properties);
extern uint32_t ecma_builtin_helper_array_index_normalize (ecma_number_t index, uint32_t length);
extern uint32_t ecma_builtin_helper_string_index_normalize (ecma_number_t index, uint32_t length);

#ifndef CONFIG_ECMA_COMPACT_PROFILE_DISABLE_DATE_BUILTIN
/* ecma-builtin-helpers-date.cpp */
extern ecma_number_t ecma_date_day (ecma_number_t time);
extern ecma_number_t ecma_date_time_within_day (ecma_number_t time);
extern ecma_number_t ecma_date_days_in_year (ecma_number_t year);
extern ecma_number_t ecma_date_day_from_year (ecma_number_t year);
extern ecma_number_t ecma_date_time_from_year (ecma_number_t year);
extern ecma_number_t ecma_date_year_from_time (ecma_number_t time);
extern ecma_number_t ecma_date_in_leap_year (ecma_number_t time);
extern ecma_number_t ecma_date_day_within_year (ecma_number_t time);
extern ecma_number_t ecma_date_month_from_time (ecma_number_t time);
extern ecma_number_t ecma_date_date_from_time (ecma_number_t time);
extern ecma_number_t ecma_date_week_day (ecma_number_t time);
extern ecma_number_t ecma_date_local_tza ();
extern ecma_number_t ecma_date_daylight_saving_ta (ecma_number_t time);
extern ecma_number_t ecma_date_local_time (ecma_number_t time);
extern ecma_number_t ecma_date_utc (ecma_number_t time);
extern ecma_number_t ecma_date_hour_from_time (ecma_number_t time);
extern ecma_number_t ecma_date_min_from_time (ecma_number_t time);
extern ecma_number_t ecma_date_sec_from_time (ecma_number_t time);
extern ecma_number_t ecma_date_ms_from_time (ecma_number_t time);
extern ecma_number_t ecma_date_make_time (ecma_number_t hour,
                                          ecma_number_t min,
                                          ecma_number_t sec,
                                          ecma_number_t ms);
extern ecma_number_t ecma_date_make_day (ecma_number_t year,
                                         ecma_number_t month,
                                         ecma_number_t date);
extern ecma_number_t ecma_date_make_date (ecma_number_t day, ecma_number_t time);
extern ecma_number_t ecma_date_time_clip (ecma_number_t time);
#endif /* !CONFIG_ECMA_COMPACT_PROFILE_DISABLE_DATE_BUILTIN */

typedef struct
{
  void **block_start_p;
  void **block_end_p;
  void **current_p;
} list_ctx_t;

typedef struct
{
  list_ctx_t property_list;
  list_ctx_t occurence_stack;

  ecma_string_t *indent_str_p;
  ecma_string_t *gap_str_p;
  ecma_object_t *replacer_function_p;
} stringify_context_t;

/* ecma-builtin-helper-json.cpp */
extern void **realloc_list (list_ctx_t *ctx);
extern void list_append (list_ctx_t *ctx, void *element);
extern void free_list (list_ctx_t *ctx);
extern bool list_has_element (list_ctx_t *ctx, void *element);
extern bool list_has_ecma_string_element (list_ctx_t *ctx, ecma_string_t *string_p);
extern bool list_is_empty (list_ctx_t *ctx);
extern void list_remove_last_element (list_ctx_t *ctx);
extern void free_list_with_ecma_string_content (list_ctx_t *ctx);

extern ecma_string_t *ecma_builtin_helper_json_create_separated_properties (list_ctx_t *partial_p,
                                                                            ecma_string_t *separator_p);
extern ecma_completion_value_t ecma_builtin_helper_json_create_formatted_json (ecma_string_t *left_bracket_p,
                                                                               ecma_string_t *right_bracket_p,
                                                                               ecma_string_t *stepback_p,
                                                                               list_ctx_t *partial_p,
                                                                               stringify_context_t *context_p);
extern ecma_completion_value_t ecma_builtin_helper_json_create_non_formatted_json (ecma_string_t *left_bracket_p,
                                                                                   ecma_string_t *right_bracket_p,
                                                                                   list_ctx_t *partial_p);
extern ecma_string_t *ecma_builtin_helper_json_create_hex_digit_ecma_string (uint8_t value);

/**
 * @}
 * @}
 */

#endif /* !ECMA_OBJECT_PROPERTY_H */
