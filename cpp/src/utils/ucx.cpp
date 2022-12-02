/**
 * Copyright (c) 2022, NVIDIA CORPORATION. All rights reserved.
 *
 * See file LICENSE for terms.
 */
#include <string>

#include <ucxx/exception.h>
#include <ucxx/utils/ucx.h>

namespace ucxx {

namespace utils {

bool assert_ucs_status(const ucs_status_t status, const std::string& msg_context)
{
  std::string msg, ucs_status;

  if (status == UCS_OK) return true;
  if (status == UCS_INPROGRESS) return false;

  // If the status is not OK or INPROGRESS it is an error
  ucs_status = ucs_status_string(status);
  if (!msg_context.empty())
    msg = std::string("[" + msg_context + "] " + std::string(ucs_status));
  else
    msg = ucs_status;
  throw ucxx::Error(msg);
}

}  // namespace utils

}  // namespace ucxx
