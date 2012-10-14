
#ifndef  __msg_structs__
#define  __msg_structs__


// generated automatically
// coded last modification:        _CODED_LAST_MODIF


#include "yaml/yaml.h"
#include "support/nullable.hpp"
#include "support/fixed_number.h"
#include "support/date_time.h"
#include "support/list.hpp"
#include "support/alarm.h"
#include "support/exec_max_frec.h"
#include "mtk_qpid/qpid_msg_support.hpp"
#include "support/mtk_string.h"
#include <qpid/messaging/Message.h>
#include "mtk_qpid/msg_control_fields.h"

#include "mtk_qpid/mtk_qpid.h"




namespace ort { 
namespace msg { 




//-------------------------------
//      sub_question
//-------------------------------    
class sub_question     
{
public:
    //  inner classes

    
    // constructor
    explicit sub_question (    const std::string&  _question,   const mtk::list<std::string >&  _answers,   const mtk::list<std::string >&  _wrong_options );
    explicit sub_question ( const qpid::types::Variant::Map&  mv );
    virtual ~sub_question (){};
    virtual std::string get_message_type_as_string       (void) const  { return "sub_question"; }
    static  std::string static_get_message_type_as_string(void)        { return "sub_question"; }
    
    

    

    
    
    
    

    // fields
    std::string                               question; 
    mtk::list<std::string >                   answers; 
    mtk::list<std::string >                   wrong_options; 



    //  ADDRESS info



    //  subject info
    

    
    
    
    
    void        before_send(void) const;
    
    void check_recomended(void) const;
};



        //  qpid_variant wrapper for dynamic
        class sub_question__qpid_map
        {
        public:
            explicit  sub_question__qpid_map ( const qpid::types::Variant::Map&  mv );
            explicit  sub_question__qpid_map ( const sub_question&  c ) : m_static(c) {}
            explicit  sub_question__qpid_map (    const std::string&  _question,   const mtk::list<std::string >&  _answers,   const mtk::list<std::string >&  _wrong_options );
            ~sub_question__qpid_map() {};
            

            sub_question                   m_static;
            qpid::types::Variant::Map           m_qpid_map;

            


            mtk::msg::sub_control_fields*   __internal_warning_control_fields;
        };
        
        

//-------------------------------
//      sub_status
//-------------------------------    
class sub_status     
{
public:
    //  inner classes

    
    // constructor
    explicit sub_status (    const mtk::DateTime&  _started,   const int&  _repetitions,   const int&  _penalizations,   const int&  _options_per_question,   const int&  _failed,   const bool&  _tildes,   const int&  _pendings );
    explicit sub_status ( const qpid::types::Variant::Map&  mv );
    virtual ~sub_status (){};
    virtual std::string get_message_type_as_string       (void) const  { return "sub_status"; }
    static  std::string static_get_message_type_as_string(void)        { return "sub_status"; }
    
    

    

    
    
    
    

    // fields
    mtk::DateTime                             started; 
    int                                       repetitions; 
    int                                       penalizations; 
    int                                       options_per_question; 
    int                                       failed; 
    bool                                      tildes; 
    int                                       pendings; 



    //  ADDRESS info



    //  subject info
    

    
    
    
    
    void        before_send(void) const;
    
    void check_recomended(void) const;
};



        //  qpid_variant wrapper for dynamic
        class sub_status__qpid_map
        {
        public:
            explicit  sub_status__qpid_map ( const qpid::types::Variant::Map&  mv );
            explicit  sub_status__qpid_map ( const sub_status&  c ) : m_static(c) {}
            explicit  sub_status__qpid_map (    const mtk::DateTime&  _started,   const int&  _repetitions,   const int&  _penalizations,   const int&  _options_per_question,   const int&  _failed,   const bool&  _tildes,   const int&  _pendings );
            ~sub_status__qpid_map() {};
            

            sub_status                   m_static;
            qpid::types::Variant::Map           m_qpid_map;

            


            mtk::msg::sub_control_fields*   __internal_warning_control_fields;
        };
        
        
    
    
    
//  fordward declarations-----------------------------------------------------------
    std::ostream& operator<< (std::ostream& o, const sub_question & c);
   YAML::Emitter& operator << (YAML::Emitter&    o, const sub_question & c);
   void           operator >> (const YAML::Node& n,       sub_question & c);

bool operator== (const sub_question& a, const sub_question& b);
bool operator!= (const sub_question& a, const sub_question& b);

    std::ostream& operator<< (std::ostream& o, const sub_status & c);
   YAML::Emitter& operator << (YAML::Emitter&    o, const sub_status & c);
   void           operator >> (const YAML::Node& n,       sub_status & c);

bool operator== (const sub_status& a, const sub_status& b);
bool operator!= (const sub_status& a, const sub_status& b);

void __internal_add2map (qpid::types::Variant::Map& map, const sub_question& a);
void __internal_add2map (qpid::types::Variant::Map& map, const mtk::nullable<sub_question>& a, const std::string& field);
void copy (sub_question& a, const qpid::types::Variant& map);
void __internal_add2map (qpid::types::Variant::Map& map, const sub_status& a);
void __internal_add2map (qpid::types::Variant::Map& map, const mtk::nullable<sub_status>& a, const std::string& field);
void copy (sub_status& a, const qpid::types::Variant& map);

    
    
    
//  fordward declarations  dynamic--------------------------------------------------------


inline std::ostream& operator<< (std::ostream& o, const sub_question__qpid_map & c) {  return (o << c.m_static << "   QPID_VAR: " << c.m_qpid_map);  };
inline YAML::Emitter& operator << (YAML::Emitter&    o, const sub_question__qpid_map & c)          {  return (o << c.m_static);  };
inline void           operator >> (const YAML::Node& n,       sub_question__qpid_map & c)          {  n  >>  c;  }

inline bool operator== (const sub_question__qpid_map& a, const sub_question__qpid_map& b)  {  return  a==b;  }
inline bool operator!= (const sub_question__qpid_map& a, const sub_question__qpid_map& b)  {  return  a!=b;  }
void __internal_add2map (qpid::types::Variant::Map& map, const sub_question__qpid_map& a);
void __internal_add2map (qpid::types::Variant::Map& map, const mtk::nullable<sub_question__qpid_map>& a, const std::string& field);
void copy (sub_question__qpid_map& a, const qpid::types::Variant& map);

inline std::ostream& operator<< (std::ostream& o, const sub_status__qpid_map & c) {  return (o << c.m_static << "   QPID_VAR: " << c.m_qpid_map);  };
inline YAML::Emitter& operator << (YAML::Emitter&    o, const sub_status__qpid_map & c)          {  return (o << c.m_static);  };
inline void           operator >> (const YAML::Node& n,       sub_status__qpid_map & c)          {  n  >>  c;  }

inline bool operator== (const sub_status__qpid_map& a, const sub_status__qpid_map& b)  {  return  a==b;  }
inline bool operator!= (const sub_status__qpid_map& a, const sub_status__qpid_map& b)  {  return  a!=b;  }
void __internal_add2map (qpid::types::Variant::Map& map, const sub_status__qpid_map& a);
void __internal_add2map (qpid::types::Variant::Map& map, const mtk::nullable<sub_status__qpid_map>& a, const std::string& field);
void copy (sub_status__qpid_map& a, const qpid::types::Variant& map);

    sub_question  __internal_get_default(sub_question *);
    
        inline sub_question__qpid_map  __internal_get_default(sub_question__qpid_map *) { return  sub_question__qpid_map(__internal_get_default((sub_question*)0));  }

    sub_status  __internal_get_default(sub_status *);
    
        inline sub_status__qpid_map  __internal_get_default(sub_status__qpid_map *) { return  sub_status__qpid_map(__internal_get_default((sub_status*)0));  }


};   //namespace ort {
};   //namespace msg {





    
template<typename T>
void   copy(mtk::nullable<T>& result, const qpid::types::Variant& v);






#endif
