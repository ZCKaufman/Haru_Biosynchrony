#ifndef _ROS_strawberry_ros_msgs_TransportsTransitDetails_h
#define _ROS_strawberry_ros_msgs_TransportsTransitDetails_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace strawberry_ros_msgs
{

  class TransportsTransitDetails : public ros::Msg
  {
    public:
      typedef const char* _departure_stop_type;
      _departure_stop_type departure_stop;
      typedef const char* _arrival_stop_type;
      _arrival_stop_type arrival_stop;
      typedef const char* _departure_time_type;
      _departure_time_type departure_time;
      typedef const char* _arrival_time_type;
      _arrival_time_type arrival_time;
      typedef const char* _line_name_type;
      _line_name_type line_name;
      typedef const char* _line_short_name_type;
      _line_short_name_type line_short_name;
      typedef const char* _line_agency_name_type;
      _line_agency_name_type line_agency_name;
      typedef const char* _line_icon_type;
      _line_icon_type line_icon;
      typedef const char* _line_vehicle_type_type;
      _line_vehicle_type_type line_vehicle_type;
      typedef const char* _trip_short_name_type;
      _trip_short_name_type trip_short_name;
      typedef const char* _headsign_type;
      _headsign_type headsign;
      typedef const char* _num_stops_type;
      _num_stops_type num_stops;

    TransportsTransitDetails():
      departure_stop(""),
      arrival_stop(""),
      departure_time(""),
      arrival_time(""),
      line_name(""),
      line_short_name(""),
      line_agency_name(""),
      line_icon(""),
      line_vehicle_type(""),
      trip_short_name(""),
      headsign(""),
      num_stops("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_departure_stop = strlen(this->departure_stop);
      varToArr(outbuffer + offset, length_departure_stop);
      offset += 4;
      memcpy(outbuffer + offset, this->departure_stop, length_departure_stop);
      offset += length_departure_stop;
      uint32_t length_arrival_stop = strlen(this->arrival_stop);
      varToArr(outbuffer + offset, length_arrival_stop);
      offset += 4;
      memcpy(outbuffer + offset, this->arrival_stop, length_arrival_stop);
      offset += length_arrival_stop;
      uint32_t length_departure_time = strlen(this->departure_time);
      varToArr(outbuffer + offset, length_departure_time);
      offset += 4;
      memcpy(outbuffer + offset, this->departure_time, length_departure_time);
      offset += length_departure_time;
      uint32_t length_arrival_time = strlen(this->arrival_time);
      varToArr(outbuffer + offset, length_arrival_time);
      offset += 4;
      memcpy(outbuffer + offset, this->arrival_time, length_arrival_time);
      offset += length_arrival_time;
      uint32_t length_line_name = strlen(this->line_name);
      varToArr(outbuffer + offset, length_line_name);
      offset += 4;
      memcpy(outbuffer + offset, this->line_name, length_line_name);
      offset += length_line_name;
      uint32_t length_line_short_name = strlen(this->line_short_name);
      varToArr(outbuffer + offset, length_line_short_name);
      offset += 4;
      memcpy(outbuffer + offset, this->line_short_name, length_line_short_name);
      offset += length_line_short_name;
      uint32_t length_line_agency_name = strlen(this->line_agency_name);
      varToArr(outbuffer + offset, length_line_agency_name);
      offset += 4;
      memcpy(outbuffer + offset, this->line_agency_name, length_line_agency_name);
      offset += length_line_agency_name;
      uint32_t length_line_icon = strlen(this->line_icon);
      varToArr(outbuffer + offset, length_line_icon);
      offset += 4;
      memcpy(outbuffer + offset, this->line_icon, length_line_icon);
      offset += length_line_icon;
      uint32_t length_line_vehicle_type = strlen(this->line_vehicle_type);
      varToArr(outbuffer + offset, length_line_vehicle_type);
      offset += 4;
      memcpy(outbuffer + offset, this->line_vehicle_type, length_line_vehicle_type);
      offset += length_line_vehicle_type;
      uint32_t length_trip_short_name = strlen(this->trip_short_name);
      varToArr(outbuffer + offset, length_trip_short_name);
      offset += 4;
      memcpy(outbuffer + offset, this->trip_short_name, length_trip_short_name);
      offset += length_trip_short_name;
      uint32_t length_headsign = strlen(this->headsign);
      varToArr(outbuffer + offset, length_headsign);
      offset += 4;
      memcpy(outbuffer + offset, this->headsign, length_headsign);
      offset += length_headsign;
      uint32_t length_num_stops = strlen(this->num_stops);
      varToArr(outbuffer + offset, length_num_stops);
      offset += 4;
      memcpy(outbuffer + offset, this->num_stops, length_num_stops);
      offset += length_num_stops;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_departure_stop;
      arrToVar(length_departure_stop, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_departure_stop; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_departure_stop-1]=0;
      this->departure_stop = (char *)(inbuffer + offset-1);
      offset += length_departure_stop;
      uint32_t length_arrival_stop;
      arrToVar(length_arrival_stop, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_arrival_stop; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_arrival_stop-1]=0;
      this->arrival_stop = (char *)(inbuffer + offset-1);
      offset += length_arrival_stop;
      uint32_t length_departure_time;
      arrToVar(length_departure_time, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_departure_time; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_departure_time-1]=0;
      this->departure_time = (char *)(inbuffer + offset-1);
      offset += length_departure_time;
      uint32_t length_arrival_time;
      arrToVar(length_arrival_time, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_arrival_time; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_arrival_time-1]=0;
      this->arrival_time = (char *)(inbuffer + offset-1);
      offset += length_arrival_time;
      uint32_t length_line_name;
      arrToVar(length_line_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_line_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_line_name-1]=0;
      this->line_name = (char *)(inbuffer + offset-1);
      offset += length_line_name;
      uint32_t length_line_short_name;
      arrToVar(length_line_short_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_line_short_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_line_short_name-1]=0;
      this->line_short_name = (char *)(inbuffer + offset-1);
      offset += length_line_short_name;
      uint32_t length_line_agency_name;
      arrToVar(length_line_agency_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_line_agency_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_line_agency_name-1]=0;
      this->line_agency_name = (char *)(inbuffer + offset-1);
      offset += length_line_agency_name;
      uint32_t length_line_icon;
      arrToVar(length_line_icon, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_line_icon; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_line_icon-1]=0;
      this->line_icon = (char *)(inbuffer + offset-1);
      offset += length_line_icon;
      uint32_t length_line_vehicle_type;
      arrToVar(length_line_vehicle_type, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_line_vehicle_type; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_line_vehicle_type-1]=0;
      this->line_vehicle_type = (char *)(inbuffer + offset-1);
      offset += length_line_vehicle_type;
      uint32_t length_trip_short_name;
      arrToVar(length_trip_short_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_trip_short_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_trip_short_name-1]=0;
      this->trip_short_name = (char *)(inbuffer + offset-1);
      offset += length_trip_short_name;
      uint32_t length_headsign;
      arrToVar(length_headsign, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_headsign; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_headsign-1]=0;
      this->headsign = (char *)(inbuffer + offset-1);
      offset += length_headsign;
      uint32_t length_num_stops;
      arrToVar(length_num_stops, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_num_stops; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_num_stops-1]=0;
      this->num_stops = (char *)(inbuffer + offset-1);
      offset += length_num_stops;
     return offset;
    }

    virtual const char * getType() override { return "strawberry_ros_msgs/TransportsTransitDetails"; };
    virtual const char * getMD5() override { return "680bd12aa776ebe245ef864573f7db61"; };

  };

}
#endif
