#ifndef _ROS_SERVICE_GetQRReading_h
#define _ROS_SERVICE_GetQRReading_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace idmind_tabletop_msgs
{

static const char GETQRREADING[] = "idmind_tabletop_msgs/GetQRReading";

  class GetQRReadingRequest : public ros::Msg
  {
    public:
      typedef float _timeout_type;
      _timeout_type timeout;

    GetQRReadingRequest():
      timeout(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_timeout;
      u_timeout.real = this->timeout;
      *(outbuffer + offset + 0) = (u_timeout.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_timeout.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_timeout.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_timeout.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->timeout);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_timeout;
      u_timeout.base = 0;
      u_timeout.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_timeout.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_timeout.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_timeout.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->timeout = u_timeout.real;
      offset += sizeof(this->timeout);
     return offset;
    }

    virtual const char * getType() override { return GETQRREADING; };
    virtual const char * getMD5() override { return "8e929ace7fd80dc265b8b96078f41e82"; };

  };

  class GetQRReadingResponse : public ros::Msg
  {
    public:
      typedef const char* _qr_reading_type;
      _qr_reading_type qr_reading;

    GetQRReadingResponse():
      qr_reading("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_qr_reading = strlen(this->qr_reading);
      varToArr(outbuffer + offset, length_qr_reading);
      offset += 4;
      memcpy(outbuffer + offset, this->qr_reading, length_qr_reading);
      offset += length_qr_reading;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_qr_reading;
      arrToVar(length_qr_reading, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_qr_reading; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_qr_reading-1]=0;
      this->qr_reading = (char *)(inbuffer + offset-1);
      offset += length_qr_reading;
     return offset;
    }

    virtual const char * getType() override { return GETQRREADING; };
    virtual const char * getMD5() override { return "996f88cd1ba09526df2a720c269f80f2"; };

  };

  class GetQRReading {
    public:
    typedef GetQRReadingRequest Request;
    typedef GetQRReadingResponse Response;
  };

}
#endif
