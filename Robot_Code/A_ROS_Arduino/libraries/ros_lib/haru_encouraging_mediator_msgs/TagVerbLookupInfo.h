#ifndef _ROS_SERVICE_TagVerbLookupInfo_h
#define _ROS_SERVICE_TagVerbLookupInfo_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/String.h"

namespace haru_encouraging_mediator_msgs
{

static const char TAGVERBLOOKUPINFO[] = "haru_encouraging_mediator_msgs/TagVerbLookupInfo";

  class TagVerbLookupInfoRequest : public ros::Msg
  {
    public:
      typedef std_msgs::String _tag_type;
      _tag_type tag;

    TagVerbLookupInfoRequest():
      tag()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->tag.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->tag.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return TAGVERBLOOKUPINFO; };
    virtual const char * getMD5() override { return "060141fb4cf35cc781d588794c0a4627"; };

  };

  class TagVerbLookupInfoResponse : public ros::Msg
  {
    public:
      typedef std_msgs::String _tag_verb_type;
      _tag_verb_type tag_verb;

    TagVerbLookupInfoResponse():
      tag_verb()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->tag_verb.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->tag_verb.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return TAGVERBLOOKUPINFO; };
    virtual const char * getMD5() override { return "46d8e0537dd43d300dd05945dbbf9223"; };

  };

  class TagVerbLookupInfo {
    public:
    typedef TagVerbLookupInfoRequest Request;
    typedef TagVerbLookupInfoResponse Response;
  };

}
#endif
