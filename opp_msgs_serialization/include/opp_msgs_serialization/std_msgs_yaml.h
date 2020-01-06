/* 
 * Copyright 2018 Southwest Research Institute
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *     http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef OPP_MSGS_SERIALIZATION_STD_MSGS_YAML
#define OPP_MSGS_SERIALIZATION_STD_MSGS_YAML

#include <std_msgs/Header.h>
#include <yaml-cpp/yaml.h>

namespace YAML
{

template<>
struct convert<ros::Time>
{
  static Node encode(const ros::Time& rhs)
  {
    Node node;
    node["sec"] = rhs.sec;
    node["nsec"] = rhs.nsec;
    return node;
  }

  static bool decode(const Node& node, ros::Time& rhs)
  {
    if (node.size() != 2) return false;

    rhs.sec = node["sec"].as<uint32_t>();
    rhs.nsec = node["nsec"].as<uint32_t>();

    return true;
  }
};

template<>
struct convert<std_msgs::Header>
{
  static Node encode(const std_msgs::Header& rhs)
  {
    Node node;
    node["seq"] = rhs.seq;
    node["stamp"] = rhs.stamp;
    node["frame_id"] = rhs.frame_id;
    return node;
  }

  static bool decode(const Node& node, std_msgs::Header& rhs)
  {
    if (node.size() != 3) return false;

    rhs.seq = node["seq"].as<uint32_t>();
    rhs.stamp = node["stamp"].as<ros::Time>();
    rhs.frame_id = node["frame_id"].as<std::string>();

    return true;
  }
};

// TODO: Duration

}

#endif // OPP_MSGS_SERIALIZATION_STD_MSGS_YAML
