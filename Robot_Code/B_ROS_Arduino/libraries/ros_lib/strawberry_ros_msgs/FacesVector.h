#ifndef _ROS_strawberry_ros_msgs_FacesVector_h
#define _ROS_strawberry_ros_msgs_FacesVector_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "strawberry_ros_msgs/Faces.h"

namespace strawberry_ros_msgs
{

  class FacesVector : public ros::Msg
  {
    public:
      uint32_t vector_of_faces_length;
      typedef strawberry_ros_msgs::Faces _vector_of_faces_type;
      _vector_of_faces_type st_vector_of_faces;
      _vector_of_faces_type * vector_of_faces;

    FacesVector():
      vector_of_faces_length(0), st_vector_of_faces(), vector_of_faces(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->vector_of_faces_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->vector_of_faces_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->vector_of_faces_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->vector_of_faces_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->vector_of_faces_length);
      for( uint32_t i = 0; i < vector_of_faces_length; i++){
      offset += this->vector_of_faces[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t vector_of_faces_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      vector_of_faces_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      vector_of_faces_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      vector_of_faces_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->vector_of_faces_length);
      if(vector_of_faces_lengthT > vector_of_faces_length)
        this->vector_of_faces = (strawberry_ros_msgs::Faces*)realloc(this->vector_of_faces, vector_of_faces_lengthT * sizeof(strawberry_ros_msgs::Faces));
      vector_of_faces_length = vector_of_faces_lengthT;
      for( uint32_t i = 0; i < vector_of_faces_length; i++){
      offset += this->st_vector_of_faces.deserialize(inbuffer + offset);
        memcpy( &(this->vector_of_faces[i]), &(this->st_vector_of_faces), sizeof(strawberry_ros_msgs::Faces));
      }
     return offset;
    }

    virtual const char * getType() override { return "strawberry_ros_msgs/FacesVector"; };
    virtual const char * getMD5() override { return "d34f1f0ad469d026b26f69d48ed05ea3"; };

  };

}
#endif
