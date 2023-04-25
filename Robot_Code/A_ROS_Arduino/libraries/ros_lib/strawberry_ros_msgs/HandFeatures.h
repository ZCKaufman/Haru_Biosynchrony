#ifndef _ROS_strawberry_ros_msgs_HandFeatures_h
#define _ROS_strawberry_ros_msgs_HandFeatures_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace strawberry_ros_msgs
{

  class HandFeatures : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef int64_t _frame_id_type;
      _frame_id_type frame_id;
      typedef uint32_t _hand_id_type;
      _hand_id_type hand_id;
      typedef const char* _label_type;
      _label_type label;
      typedef int64_t _hand_feature_type;
      _hand_feature_type hand_feature;
      uint32_t finger_feats_length;
      typedef int64_t _finger_feats_type;
      _finger_feats_type st_finger_feats;
      _finger_feats_type * finger_feats;
      uint32_t lfinger_list_discrs_length;
      typedef float _lfinger_list_discrs_type;
      _lfinger_list_discrs_type st_lfinger_list_discrs;
      _lfinger_list_discrs_type * lfinger_list_discrs;
      uint32_t rfinger_list_discrs_length;
      typedef float _rfinger_list_discrs_type;
      _rfinger_list_discrs_type st_rfinger_list_discrs;
      _rfinger_list_discrs_type * rfinger_list_discrs;
      typedef float _lhand_roll_discr_type;
      _lhand_roll_discr_type lhand_roll_discr;
      typedef float _rhand_roll_discr_type;
      _rhand_roll_discr_type rhand_roll_discr;
      typedef float _hand_dist_discr_type;
      _hand_dist_discr_type hand_dist_discr;
      typedef float _lpalm_opening_discr_type;
      _lpalm_opening_discr_type lpalm_opening_discr;
      typedef float _rpalm_opening_discr_type;
      _rpalm_opening_discr_type rpalm_opening_discr;
      typedef float _lwrist_wave_discr_type;
      _lwrist_wave_discr_type lwrist_wave_discr;
      typedef float _rwrist_wave_discr_type;
      _rwrist_wave_discr_type rwrist_wave_discr;
      typedef float _lwrist_prox_discr_type;
      _lwrist_prox_discr_type lwrist_prox_discr;
      typedef float _rwrist_prox_discr_type;
      _rwrist_prox_discr_type rwrist_prox_discr;
      typedef float _lwrist_height_discr_type;
      _lwrist_height_discr_type lwrist_height_discr;
      typedef float _rwrist_height_discr_type;
      _rwrist_height_discr_type rwrist_height_discr;

    HandFeatures():
      header(),
      frame_id(0),
      hand_id(0),
      label(""),
      hand_feature(0),
      finger_feats_length(0), st_finger_feats(), finger_feats(nullptr),
      lfinger_list_discrs_length(0), st_lfinger_list_discrs(), lfinger_list_discrs(nullptr),
      rfinger_list_discrs_length(0), st_rfinger_list_discrs(), rfinger_list_discrs(nullptr),
      lhand_roll_discr(0),
      rhand_roll_discr(0),
      hand_dist_discr(0),
      lpalm_opening_discr(0),
      rpalm_opening_discr(0),
      lwrist_wave_discr(0),
      rwrist_wave_discr(0),
      lwrist_prox_discr(0),
      rwrist_prox_discr(0),
      lwrist_height_discr(0),
      rwrist_height_discr(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        int64_t real;
        uint64_t base;
      } u_frame_id;
      u_frame_id.real = this->frame_id;
      *(outbuffer + offset + 0) = (u_frame_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_frame_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_frame_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_frame_id.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_frame_id.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_frame_id.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_frame_id.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_frame_id.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->frame_id);
      *(outbuffer + offset + 0) = (this->hand_id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->hand_id >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->hand_id >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->hand_id >> (8 * 3)) & 0xFF;
      offset += sizeof(this->hand_id);
      uint32_t length_label = strlen(this->label);
      varToArr(outbuffer + offset, length_label);
      offset += 4;
      memcpy(outbuffer + offset, this->label, length_label);
      offset += length_label;
      union {
        int64_t real;
        uint64_t base;
      } u_hand_feature;
      u_hand_feature.real = this->hand_feature;
      *(outbuffer + offset + 0) = (u_hand_feature.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_hand_feature.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_hand_feature.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_hand_feature.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_hand_feature.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_hand_feature.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_hand_feature.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_hand_feature.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->hand_feature);
      *(outbuffer + offset + 0) = (this->finger_feats_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->finger_feats_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->finger_feats_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->finger_feats_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->finger_feats_length);
      for( uint32_t i = 0; i < finger_feats_length; i++){
      union {
        int64_t real;
        uint64_t base;
      } u_finger_featsi;
      u_finger_featsi.real = this->finger_feats[i];
      *(outbuffer + offset + 0) = (u_finger_featsi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_finger_featsi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_finger_featsi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_finger_featsi.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_finger_featsi.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_finger_featsi.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_finger_featsi.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_finger_featsi.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->finger_feats[i]);
      }
      *(outbuffer + offset + 0) = (this->lfinger_list_discrs_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->lfinger_list_discrs_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->lfinger_list_discrs_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->lfinger_list_discrs_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->lfinger_list_discrs_length);
      for( uint32_t i = 0; i < lfinger_list_discrs_length; i++){
      union {
        float real;
        uint32_t base;
      } u_lfinger_list_discrsi;
      u_lfinger_list_discrsi.real = this->lfinger_list_discrs[i];
      *(outbuffer + offset + 0) = (u_lfinger_list_discrsi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_lfinger_list_discrsi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_lfinger_list_discrsi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_lfinger_list_discrsi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->lfinger_list_discrs[i]);
      }
      *(outbuffer + offset + 0) = (this->rfinger_list_discrs_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->rfinger_list_discrs_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->rfinger_list_discrs_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->rfinger_list_discrs_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->rfinger_list_discrs_length);
      for( uint32_t i = 0; i < rfinger_list_discrs_length; i++){
      union {
        float real;
        uint32_t base;
      } u_rfinger_list_discrsi;
      u_rfinger_list_discrsi.real = this->rfinger_list_discrs[i];
      *(outbuffer + offset + 0) = (u_rfinger_list_discrsi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_rfinger_list_discrsi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_rfinger_list_discrsi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_rfinger_list_discrsi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->rfinger_list_discrs[i]);
      }
      union {
        float real;
        uint32_t base;
      } u_lhand_roll_discr;
      u_lhand_roll_discr.real = this->lhand_roll_discr;
      *(outbuffer + offset + 0) = (u_lhand_roll_discr.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_lhand_roll_discr.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_lhand_roll_discr.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_lhand_roll_discr.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->lhand_roll_discr);
      union {
        float real;
        uint32_t base;
      } u_rhand_roll_discr;
      u_rhand_roll_discr.real = this->rhand_roll_discr;
      *(outbuffer + offset + 0) = (u_rhand_roll_discr.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_rhand_roll_discr.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_rhand_roll_discr.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_rhand_roll_discr.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->rhand_roll_discr);
      union {
        float real;
        uint32_t base;
      } u_hand_dist_discr;
      u_hand_dist_discr.real = this->hand_dist_discr;
      *(outbuffer + offset + 0) = (u_hand_dist_discr.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_hand_dist_discr.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_hand_dist_discr.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_hand_dist_discr.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->hand_dist_discr);
      union {
        float real;
        uint32_t base;
      } u_lpalm_opening_discr;
      u_lpalm_opening_discr.real = this->lpalm_opening_discr;
      *(outbuffer + offset + 0) = (u_lpalm_opening_discr.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_lpalm_opening_discr.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_lpalm_opening_discr.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_lpalm_opening_discr.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->lpalm_opening_discr);
      union {
        float real;
        uint32_t base;
      } u_rpalm_opening_discr;
      u_rpalm_opening_discr.real = this->rpalm_opening_discr;
      *(outbuffer + offset + 0) = (u_rpalm_opening_discr.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_rpalm_opening_discr.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_rpalm_opening_discr.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_rpalm_opening_discr.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->rpalm_opening_discr);
      union {
        float real;
        uint32_t base;
      } u_lwrist_wave_discr;
      u_lwrist_wave_discr.real = this->lwrist_wave_discr;
      *(outbuffer + offset + 0) = (u_lwrist_wave_discr.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_lwrist_wave_discr.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_lwrist_wave_discr.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_lwrist_wave_discr.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->lwrist_wave_discr);
      union {
        float real;
        uint32_t base;
      } u_rwrist_wave_discr;
      u_rwrist_wave_discr.real = this->rwrist_wave_discr;
      *(outbuffer + offset + 0) = (u_rwrist_wave_discr.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_rwrist_wave_discr.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_rwrist_wave_discr.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_rwrist_wave_discr.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->rwrist_wave_discr);
      union {
        float real;
        uint32_t base;
      } u_lwrist_prox_discr;
      u_lwrist_prox_discr.real = this->lwrist_prox_discr;
      *(outbuffer + offset + 0) = (u_lwrist_prox_discr.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_lwrist_prox_discr.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_lwrist_prox_discr.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_lwrist_prox_discr.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->lwrist_prox_discr);
      union {
        float real;
        uint32_t base;
      } u_rwrist_prox_discr;
      u_rwrist_prox_discr.real = this->rwrist_prox_discr;
      *(outbuffer + offset + 0) = (u_rwrist_prox_discr.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_rwrist_prox_discr.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_rwrist_prox_discr.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_rwrist_prox_discr.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->rwrist_prox_discr);
      union {
        float real;
        uint32_t base;
      } u_lwrist_height_discr;
      u_lwrist_height_discr.real = this->lwrist_height_discr;
      *(outbuffer + offset + 0) = (u_lwrist_height_discr.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_lwrist_height_discr.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_lwrist_height_discr.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_lwrist_height_discr.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->lwrist_height_discr);
      union {
        float real;
        uint32_t base;
      } u_rwrist_height_discr;
      u_rwrist_height_discr.real = this->rwrist_height_discr;
      *(outbuffer + offset + 0) = (u_rwrist_height_discr.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_rwrist_height_discr.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_rwrist_height_discr.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_rwrist_height_discr.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->rwrist_height_discr);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        int64_t real;
        uint64_t base;
      } u_frame_id;
      u_frame_id.base = 0;
      u_frame_id.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_frame_id.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_frame_id.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_frame_id.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_frame_id.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_frame_id.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_frame_id.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_frame_id.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->frame_id = u_frame_id.real;
      offset += sizeof(this->frame_id);
      this->hand_id =  ((uint32_t) (*(inbuffer + offset)));
      this->hand_id |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->hand_id |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->hand_id |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->hand_id);
      uint32_t length_label;
      arrToVar(length_label, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_label; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_label-1]=0;
      this->label = (char *)(inbuffer + offset-1);
      offset += length_label;
      union {
        int64_t real;
        uint64_t base;
      } u_hand_feature;
      u_hand_feature.base = 0;
      u_hand_feature.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_hand_feature.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_hand_feature.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_hand_feature.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_hand_feature.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_hand_feature.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_hand_feature.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_hand_feature.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->hand_feature = u_hand_feature.real;
      offset += sizeof(this->hand_feature);
      uint32_t finger_feats_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      finger_feats_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      finger_feats_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      finger_feats_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->finger_feats_length);
      if(finger_feats_lengthT > finger_feats_length)
        this->finger_feats = (int64_t*)realloc(this->finger_feats, finger_feats_lengthT * sizeof(int64_t));
      finger_feats_length = finger_feats_lengthT;
      for( uint32_t i = 0; i < finger_feats_length; i++){
      union {
        int64_t real;
        uint64_t base;
      } u_st_finger_feats;
      u_st_finger_feats.base = 0;
      u_st_finger_feats.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_finger_feats.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_finger_feats.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_finger_feats.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_finger_feats.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_finger_feats.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_finger_feats.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_finger_feats.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_finger_feats = u_st_finger_feats.real;
      offset += sizeof(this->st_finger_feats);
        memcpy( &(this->finger_feats[i]), &(this->st_finger_feats), sizeof(int64_t));
      }
      uint32_t lfinger_list_discrs_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      lfinger_list_discrs_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      lfinger_list_discrs_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      lfinger_list_discrs_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->lfinger_list_discrs_length);
      if(lfinger_list_discrs_lengthT > lfinger_list_discrs_length)
        this->lfinger_list_discrs = (float*)realloc(this->lfinger_list_discrs, lfinger_list_discrs_lengthT * sizeof(float));
      lfinger_list_discrs_length = lfinger_list_discrs_lengthT;
      for( uint32_t i = 0; i < lfinger_list_discrs_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_lfinger_list_discrs;
      u_st_lfinger_list_discrs.base = 0;
      u_st_lfinger_list_discrs.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_lfinger_list_discrs.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_lfinger_list_discrs.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_lfinger_list_discrs.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_lfinger_list_discrs = u_st_lfinger_list_discrs.real;
      offset += sizeof(this->st_lfinger_list_discrs);
        memcpy( &(this->lfinger_list_discrs[i]), &(this->st_lfinger_list_discrs), sizeof(float));
      }
      uint32_t rfinger_list_discrs_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      rfinger_list_discrs_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      rfinger_list_discrs_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      rfinger_list_discrs_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->rfinger_list_discrs_length);
      if(rfinger_list_discrs_lengthT > rfinger_list_discrs_length)
        this->rfinger_list_discrs = (float*)realloc(this->rfinger_list_discrs, rfinger_list_discrs_lengthT * sizeof(float));
      rfinger_list_discrs_length = rfinger_list_discrs_lengthT;
      for( uint32_t i = 0; i < rfinger_list_discrs_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_rfinger_list_discrs;
      u_st_rfinger_list_discrs.base = 0;
      u_st_rfinger_list_discrs.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_rfinger_list_discrs.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_rfinger_list_discrs.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_rfinger_list_discrs.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_rfinger_list_discrs = u_st_rfinger_list_discrs.real;
      offset += sizeof(this->st_rfinger_list_discrs);
        memcpy( &(this->rfinger_list_discrs[i]), &(this->st_rfinger_list_discrs), sizeof(float));
      }
      union {
        float real;
        uint32_t base;
      } u_lhand_roll_discr;
      u_lhand_roll_discr.base = 0;
      u_lhand_roll_discr.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_lhand_roll_discr.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_lhand_roll_discr.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_lhand_roll_discr.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->lhand_roll_discr = u_lhand_roll_discr.real;
      offset += sizeof(this->lhand_roll_discr);
      union {
        float real;
        uint32_t base;
      } u_rhand_roll_discr;
      u_rhand_roll_discr.base = 0;
      u_rhand_roll_discr.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_rhand_roll_discr.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_rhand_roll_discr.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_rhand_roll_discr.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->rhand_roll_discr = u_rhand_roll_discr.real;
      offset += sizeof(this->rhand_roll_discr);
      union {
        float real;
        uint32_t base;
      } u_hand_dist_discr;
      u_hand_dist_discr.base = 0;
      u_hand_dist_discr.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_hand_dist_discr.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_hand_dist_discr.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_hand_dist_discr.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->hand_dist_discr = u_hand_dist_discr.real;
      offset += sizeof(this->hand_dist_discr);
      union {
        float real;
        uint32_t base;
      } u_lpalm_opening_discr;
      u_lpalm_opening_discr.base = 0;
      u_lpalm_opening_discr.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_lpalm_opening_discr.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_lpalm_opening_discr.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_lpalm_opening_discr.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->lpalm_opening_discr = u_lpalm_opening_discr.real;
      offset += sizeof(this->lpalm_opening_discr);
      union {
        float real;
        uint32_t base;
      } u_rpalm_opening_discr;
      u_rpalm_opening_discr.base = 0;
      u_rpalm_opening_discr.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_rpalm_opening_discr.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_rpalm_opening_discr.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_rpalm_opening_discr.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->rpalm_opening_discr = u_rpalm_opening_discr.real;
      offset += sizeof(this->rpalm_opening_discr);
      union {
        float real;
        uint32_t base;
      } u_lwrist_wave_discr;
      u_lwrist_wave_discr.base = 0;
      u_lwrist_wave_discr.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_lwrist_wave_discr.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_lwrist_wave_discr.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_lwrist_wave_discr.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->lwrist_wave_discr = u_lwrist_wave_discr.real;
      offset += sizeof(this->lwrist_wave_discr);
      union {
        float real;
        uint32_t base;
      } u_rwrist_wave_discr;
      u_rwrist_wave_discr.base = 0;
      u_rwrist_wave_discr.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_rwrist_wave_discr.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_rwrist_wave_discr.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_rwrist_wave_discr.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->rwrist_wave_discr = u_rwrist_wave_discr.real;
      offset += sizeof(this->rwrist_wave_discr);
      union {
        float real;
        uint32_t base;
      } u_lwrist_prox_discr;
      u_lwrist_prox_discr.base = 0;
      u_lwrist_prox_discr.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_lwrist_prox_discr.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_lwrist_prox_discr.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_lwrist_prox_discr.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->lwrist_prox_discr = u_lwrist_prox_discr.real;
      offset += sizeof(this->lwrist_prox_discr);
      union {
        float real;
        uint32_t base;
      } u_rwrist_prox_discr;
      u_rwrist_prox_discr.base = 0;
      u_rwrist_prox_discr.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_rwrist_prox_discr.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_rwrist_prox_discr.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_rwrist_prox_discr.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->rwrist_prox_discr = u_rwrist_prox_discr.real;
      offset += sizeof(this->rwrist_prox_discr);
      union {
        float real;
        uint32_t base;
      } u_lwrist_height_discr;
      u_lwrist_height_discr.base = 0;
      u_lwrist_height_discr.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_lwrist_height_discr.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_lwrist_height_discr.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_lwrist_height_discr.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->lwrist_height_discr = u_lwrist_height_discr.real;
      offset += sizeof(this->lwrist_height_discr);
      union {
        float real;
        uint32_t base;
      } u_rwrist_height_discr;
      u_rwrist_height_discr.base = 0;
      u_rwrist_height_discr.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_rwrist_height_discr.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_rwrist_height_discr.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_rwrist_height_discr.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->rwrist_height_discr = u_rwrist_height_discr.real;
      offset += sizeof(this->rwrist_height_discr);
     return offset;
    }

    virtual const char * getType() override { return "strawberry_ros_msgs/HandFeatures"; };
    virtual const char * getMD5() override { return "3f7268f237da0eae8c71d73a243e4690"; };

  };

}
#endif
