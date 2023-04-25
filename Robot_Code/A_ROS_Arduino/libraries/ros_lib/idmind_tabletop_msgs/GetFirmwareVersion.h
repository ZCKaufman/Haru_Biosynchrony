#ifndef _ROS_SERVICE_GetFirmwareVersion_h
#define _ROS_SERVICE_GetFirmwareVersion_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace idmind_tabletop_msgs
{

static const char GETFIRMWAREVERSION[] = "idmind_tabletop_msgs/GetFirmwareVersion";

  class GetFirmwareVersionRequest : public ros::Msg
  {
    public:

    GetFirmwareVersionRequest()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
     return offset;
    }

    virtual const char * getType() override { return GETFIRMWAREVERSION; };
    virtual const char * getMD5() override { return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class GetFirmwareVersionResponse : public ros::Msg
  {
    public:
      typedef const char* _firmware_version_type;
      _firmware_version_type firmware_version;

    GetFirmwareVersionResponse():
      firmware_version("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_firmware_version = strlen(this->firmware_version);
      varToArr(outbuffer + offset, length_firmware_version);
      offset += 4;
      memcpy(outbuffer + offset, this->firmware_version, length_firmware_version);
      offset += length_firmware_version;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_firmware_version;
      arrToVar(length_firmware_version, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_firmware_version; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_firmware_version-1]=0;
      this->firmware_version = (char *)(inbuffer + offset-1);
      offset += length_firmware_version;
     return offset;
    }

    virtual const char * getType() override { return GETFIRMWAREVERSION; };
    virtual const char * getMD5() override { return "968367e081bb6dba33b3daf3e01dab62"; };

  };

  class GetFirmwareVersion {
    public:
    typedef GetFirmwareVersionRequest Request;
    typedef GetFirmwareVersionResponse Response;
  };

}
#endif
