#ifndef _ROS_haru_encouraging_mediator_msgs_InteractionState_h
#define _ROS_haru_encouraging_mediator_msgs_InteractionState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "std_msgs/String.h"
#include "std_msgs/UInt16.h"

namespace haru_encouraging_mediator_msgs
{

  class InteractionState : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef std_msgs::String _country_type;
      _country_type country;
      typedef std_msgs::UInt16 _country_id_type;
      _country_id_type country_id;
      typedef std_msgs::String _stage_type;
      _stage_type stage;
      typedef std_msgs::UInt16 _stage_id_type;
      _stage_id_type stage_id;
      typedef std_msgs::String _sub_stage_type;
      _sub_stage_type sub_stage;
      typedef std_msgs::UInt16 _sub_stage_id_type;
      _sub_stage_id_type sub_stage_id;
      typedef std_msgs::UInt16 _number_of_sub_stages_type;
      _number_of_sub_stages_type number_of_sub_stages;
      typedef std_msgs::String _description_type;
      _description_type description;

    InteractionState():
      header(),
      country(),
      country_id(),
      stage(),
      stage_id(),
      sub_stage(),
      sub_stage_id(),
      number_of_sub_stages(),
      description()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->country.serialize(outbuffer + offset);
      offset += this->country_id.serialize(outbuffer + offset);
      offset += this->stage.serialize(outbuffer + offset);
      offset += this->stage_id.serialize(outbuffer + offset);
      offset += this->sub_stage.serialize(outbuffer + offset);
      offset += this->sub_stage_id.serialize(outbuffer + offset);
      offset += this->number_of_sub_stages.serialize(outbuffer + offset);
      offset += this->description.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->country.deserialize(inbuffer + offset);
      offset += this->country_id.deserialize(inbuffer + offset);
      offset += this->stage.deserialize(inbuffer + offset);
      offset += this->stage_id.deserialize(inbuffer + offset);
      offset += this->sub_stage.deserialize(inbuffer + offset);
      offset += this->sub_stage_id.deserialize(inbuffer + offset);
      offset += this->number_of_sub_stages.deserialize(inbuffer + offset);
      offset += this->description.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "haru_encouraging_mediator_msgs/InteractionState"; };
    virtual const char * getMD5() override { return "bb715692a077dc4ece15069b521296cd"; };

  };

}
#endif
