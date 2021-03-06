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

#include <aws/machinelearning/model/InvalidInputException.h>
#include <aws/core/utils/json/JsonSerializer.h>

#include <utility>

using namespace Aws::Utils::Json;
using namespace Aws::Utils;

namespace Aws
{
namespace MachineLearning
{
namespace Model
{

InvalidInputException::InvalidInputException() : 
    m_messageHasBeenSet(false),
    m_code(0),
    m_codeHasBeenSet(false)
{
}

InvalidInputException::InvalidInputException(JsonView jsonValue) : 
    m_messageHasBeenSet(false),
    m_code(0),
    m_codeHasBeenSet(false)
{
  *this = jsonValue;
}

InvalidInputException& InvalidInputException::operator =(JsonView jsonValue)
{
  if(jsonValue.ValueExists("message"))
  {
    m_message = jsonValue.GetString("message");

    m_messageHasBeenSet = true;
  }

  if(jsonValue.ValueExists("code"))
  {
    m_code = jsonValue.GetInteger("code");

    m_codeHasBeenSet = true;
  }

  return *this;
}

JsonValue InvalidInputException::Jsonize() const
{
  JsonValue payload;

  if(m_messageHasBeenSet)
  {
   payload.WithString("message", m_message);

  }

  if(m_codeHasBeenSet)
  {
   payload.WithInteger("code", m_code);

  }

  return payload;
}

} // namespace Model
} // namespace MachineLearning
} // namespace Aws
