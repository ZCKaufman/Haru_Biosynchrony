#ifndef _ROS_haru_encouraging_mediator_msgs_PseudoUserRegistrationResult_h
#define _ROS_haru_encouraging_mediator_msgs_PseudoUserRegistrationResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "std_msgs/String.h"
#include "std_msgs/UInt8.h"
#include "sensor_msgs/Image.h"

namespace haru_encouraging_mediator_msgs
{

  class PseudoUserRegistrationResult : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef std_msgs::String _user_name_type;
      _user_name_type user_name;
      typedef std_msgs::UInt8 _ipad_id_type;
      _ipad_id_type ipad_id;
      typedef sensor_msgs::Image _avatar_type;
      _avatar_type avatar;

    PseudoUserRegistrationResult():
      header(),
      user_name(),
      ipad_id(),
      avatar()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->user_name.serialize(outbuffer + offset);
      offset += this->ipad_id.serialize(outbuffer + offset);
      offset += this->avatar.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->user_name.deserialize(inbuffer + offset);
      offset += this->ipad_id.deserialize(inbuffer + offset);
      offset += this->avatar.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "haru_encouraging_mediator_msgs/PseudoUserRegistrationResult"; };
    virtual const char * getMD5() override { return "ff71fb2fc0a38f793b4236dc7806565d"; };

  };

}
#endif
