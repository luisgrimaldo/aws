﻿/*
* Copyright 2010-2017 Amazon.com, Inc. or its affiliates. All Rights Reserved.
*
* Licensed under the Apache License, Version 2.0 (the "License").
* You may not use this file except in compliance with the License.
* A copy of the License is located at
*
*  http://aws.amazon.com/apache2.0
*
* or in the "license" file accompanying this file. This file is distributed
* on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
* express or implied. See the License for the specific language governing
* permissions and limitations under the License.
*/

#include <aws/sso-oidc/model/UnauthorizedClientException.h>
#include <aws/core/utils/json/JsonSerializer.h>

#include <utility>

using namespace Aws::Utils::Json;
using namespace Aws::Utils;

namespace Aws
{
namespace SSOOIDC
{
namespace Model
{

UnauthorizedClientException::UnauthorizedClientException() : 
    m_errorHasBeenSet(false),
    m_error_descriptionHasBeenSet(false)
{
}

UnauthorizedClientException::UnauthorizedClientException(JsonView jsonValue) : 
    m_errorHasBeenSet(false),
    m_error_descriptionHasBeenSet(false)
{
  *this = jsonValue;
}

UnauthorizedClientException& UnauthorizedClientException::operator =(JsonView jsonValue)
{
  if(jsonValue.ValueExists("error"))
  {
    m_error = jsonValue.GetString("error");

    m_errorHasBeenSet = true;
  }

  if(jsonValue.ValueExists("error_description"))
  {
    m_error_description = jsonValue.GetString("error_description");

    m_error_descriptionHasBeenSet = true;
  }

  return *this;
}

JsonValue UnauthorizedClientException::Jsonize() const
{
  JsonValue payload;

  if(m_errorHasBeenSet)
  {
   payload.WithString("error", m_error);

  }

  if(m_error_descriptionHasBeenSet)
  {
   payload.WithString("error_description", m_error_description);

  }

  return payload;
}

} // namespace Model
} // namespace SSOOIDC
} // namespace Aws
