#ifndef _ROS_haru_encouraging_mediator_msgs_UnityProjectorWherebyCreateMeetingResponse_h
#define _ROS_haru_encouraging_mediator_msgs_UnityProjectorWherebyCreateMeetingResponse_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace haru_encouraging_mediator_msgs
{

  class UnityProjectorWherebyCreateMeetingResponse : public ros::Msg
  {
    public:
      typedef const char* _roomUrl_type;
      _roomUrl_type roomUrl;
      typedef const char* _hostRoomUrl_type;
      _hostRoomUrl_type hostRoomUrl;
      typedef const char* _viewerRoomUrl_type;
      _viewerRoomUrl_type viewerRoomUrl;

    UnityProjectorWherebyCreateMeetingResponse():
      roomUrl(""),
      hostRoomUrl(""),
      viewerRoomUrl("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_roomUrl = strlen(this->roomUrl);
      varToArr(outbuffer + offset, length_roomUrl);
      offset += 4;
      memcpy(outbuffer + offset, this->roomUrl, length_roomUrl);
      offset += length_roomUrl;
      uint32_t length_hostRoomUrl = strlen(this->hostRoomUrl);
      varToArr(outbuffer + offset, length_hostRoomUrl);
      offset += 4;
      memcpy(outbuffer + offset, this->hostRoomUrl, length_hostRoomUrl);
      offset += length_hostRoomUrl;
      uint32_t length_viewerRoomUrl = strlen(this->viewerRoomUrl);
      varToArr(outbuffer + offset, length_viewerRoomUrl);
      offset += 4;
      memcpy(outbuffer + offset, this->viewerRoomUrl, length_viewerRoomUrl);
      offset += length_viewerRoomUrl;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_roomUrl;
      arrToVar(length_roomUrl, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_roomUrl; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_roomUrl-1]=0;
      this->roomUrl = (char *)(inbuffer + offset-1);
      offset += length_roomUrl;
      uint32_t length_hostRoomUrl;
      arrToVar(length_hostRoomUrl, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_hostRoomUrl; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_hostRoomUrl-1]=0;
      this->hostRoomUrl = (char *)(inbuffer + offset-1);
      offset += length_hostRoomUrl;
      uint32_t length_viewerRoomUrl;
      arrToVar(length_viewerRoomUrl, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_viewerRoomUrl; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_viewerRoomUrl-1]=0;
      this->viewerRoomUrl = (char *)(inbuffer + offset-1);
      offset += length_viewerRoomUrl;
     return offset;
    }

    virtual const char * getType() override { return "haru_encouraging_mediator_msgs/UnityProjectorWherebyCreateMeetingResponse"; };
    virtual const char * getMD5() override { return "a186d5f7efe8a41d2dfcc17bf0e9510f"; };

  };

}
#endif
