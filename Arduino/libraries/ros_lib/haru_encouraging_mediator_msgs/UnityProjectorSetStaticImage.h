#ifndef _ROS_haru_encouraging_mediator_msgs_UnityProjectorSetStaticImage_h
#define _ROS_haru_encouraging_mediator_msgs_UnityProjectorSetStaticImage_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace haru_encouraging_mediator_msgs
{

  class UnityProjectorSetStaticImage : public ros::Msg
  {
    public:
      typedef bool _activate_static_image_type;
      _activate_static_image_type activate_static_image;
      typedef const char* _image_file_type;
      _image_file_type image_file;

    UnityProjectorSetStaticImage():
      activate_static_image(0),
      image_file("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_activate_static_image;
      u_activate_static_image.real = this->activate_static_image;
      *(outbuffer + offset + 0) = (u_activate_static_image.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->activate_static_image);
      uint32_t length_image_file = strlen(this->image_file);
      varToArr(outbuffer + offset, length_image_file);
      offset += 4;
      memcpy(outbuffer + offset, this->image_file, length_image_file);
      offset += length_image_file;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_activate_static_image;
      u_activate_static_image.base = 0;
      u_activate_static_image.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->activate_static_image = u_activate_static_image.real;
      offset += sizeof(this->activate_static_image);
      uint32_t length_image_file;
      arrToVar(length_image_file, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_image_file; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_image_file-1]=0;
      this->image_file = (char *)(inbuffer + offset-1);
      offset += length_image_file;
     return offset;
    }

    virtual const char * getType() override { return "haru_encouraging_mediator_msgs/UnityProjectorSetStaticImage"; };
    virtual const char * getMD5() override { return "bc08ba6e96b86e5dd5bf4f9f83d227c6"; };

  };

}
#endif
