#ifndef _ROS_mech_ros_msgs_BasicLidar_h
#define _ROS_mech_ros_msgs_BasicLidar_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace mech_ros_msgs
{

  class BasicLidar : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _distance_type;
      _distance_type distance;
      typedef float _strength_type;
      _strength_type strength;

    BasicLidar():
      header(),
      distance(0),
      strength(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_distance;
      u_distance.real = this->distance;
      *(outbuffer + offset + 0) = (u_distance.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_distance.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_distance.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_distance.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->distance);
      union {
        float real;
        uint32_t base;
      } u_strength;
      u_strength.real = this->strength;
      *(outbuffer + offset + 0) = (u_strength.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_strength.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_strength.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_strength.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->strength);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_distance;
      u_distance.base = 0;
      u_distance.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_distance.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_distance.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_distance.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->distance = u_distance.real;
      offset += sizeof(this->distance);
      union {
        float real;
        uint32_t base;
      } u_strength;
      u_strength.base = 0;
      u_strength.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_strength.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_strength.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_strength.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->strength = u_strength.real;
      offset += sizeof(this->strength);
     return offset;
    }

    const char * getType(){ return "mech_ros_msgs/BasicLidar"; };
    const char * getMD5(){ return "5d0efb0466671995734d152c8b5d7456"; };

  };

}
#endif