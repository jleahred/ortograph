
// generated automatically
// coded last modification:        $CODED_LAST_MODIF


#include "support/mtk_double.h"
#include "support/fixed_number.h"
#include "support/date_time.h"

#include "msg_structs.h"

namespace ort { 
namespace msg { 







    inline std::string  __internal_get_default(std::string*)
    {
        return std::string();
    }

    inline mtk::Double __internal_get_default(mtk::Double*)
    {
        return mtk::Double(0.0);
    }
    inline mtk::FixedNumber __internal_get_default(mtk::FixedNumber*)
    {
        return mtk::FixedNumber(mtk::fnDouble(0), mtk::fnDec(0), mtk::fnInc(1));
    }
    inline mtk::fnExt  __internal_get_default(mtk::fnExt*)
    {
        return mtk::fnExt(mtk::fnDec(0), mtk::fnInc(1));
    }
    
    inline mtk::DateTime __internal_get_default(mtk::DateTime*)
    {
        return mtk::DateTime(mtk::dtYear(2000), mtk::dtMonth(1), mtk::dtDay(1));
    }
    inline mtk::dtTimeQuantity __internal_get_default(mtk::dtTimeQuantity*)
    {
        return mtk::dtTimeQuantity(mtk::dtHours(0), mtk::dtMinutes(0), mtk::dtSeconds(0), mtk::dtMilliseconds(0));
    }
    inline bool __internal_get_default(bool*)
    {
        return false;
    }
    inline int8_t __internal_get_default(int8_t*)
    {
        return 0;
    }
    inline int16_t  __internal_get_default(int16_t*)
    {
        return 0;
    }
    inline int32_t  __internal_get_default(int32_t*)
    {
        return 0;
    }

    template<typename T>
    mtk::list<T>  __internal_get_default(mtk::list<T>*)
    {
        return mtk::list<T>();
    }



    
template<typename T>
std::ostream& operator<< (std::ostream& o, const mtk::list<T>& list)
{
    typename mtk::list<T>::const_iterator it = list.begin();
    o << "[";
    while (it!= list.end())
    {
        o << *it << ", ";
        ++it;
    }
    o << "]";
    return o;
}



template<typename T>
bool operator== (const mtk::list<T>& l1, const mtk::list<T>& l2)
{
    if (l1.size() != l2.size())     return false;
    
    typename mtk::list<T>::const_iterator it1 = l1.begin();
    typename mtk::list<T>::const_iterator it2 = l2.begin();
    while (it1!= l1.end())
    {
        if (*it1 != *it2)       return false;
        ++it1;
        ++it2;
    }
    return true;
}



inline void  copy(mtk::FixedNumber& result, const qpid::types::Variant& v)
{
    result = ({   std::map<qpid::types::Variant::Map::key_type, qpid::types::Variant> ifn = /*it->second*/v.asMap();
                    mtk::FixedNumber(mtk::fnIntCode(ifn["n"].asInt32()), mtk::fnDec(ifn["d"].asInt8()), mtk::fnInc(ifn["i"].asInt8()));
            });
}

inline void  copy(mtk::fnExt& result, const qpid::types::Variant& v)
{
    result = ({   std::map<qpid::types::Variant::Map::key_type, qpid::types::Variant> ifn = /*it->second*/v.asMap();
                    mtk::fnExt(mtk::fnDec(ifn["d"].asInt8()), mtk::fnInc(ifn["i"].asInt8()));
            });
}

inline void   copy(std::string& result, const qpid::types::Variant& v)
{
    result = v.asString();
}



inline void   copy(char& result, const qpid::types::Variant& v)
{
    result = v.asInt8();
}


inline void copy(mtk::DateTime& result, const qpid::types::Variant& v)
{
    result =  WARNING_do_not_use_it__I_coul_kill_you_for_it__get_DateTime_from_time_quantity(mtk::dtTimeQuantity(mtk::dtTimeQuantitySerialNumber(v.asDouble())));
}

inline void copy(mtk::dtTimeQuantity& result, const qpid::types::Variant& v)
{
    result =  mtk::dtTimeQuantity(mtk::dtTimeQuantitySerialNumber(v.asDouble()));
}

inline void copy(int8_t& result, const qpid::types::Variant& v)
{
    result =  v.asInt8();
}

inline void copy(int16_t& result, const qpid::types::Variant& v)
{
    result =  v.asInt16();
}

inline void copy(int32_t& result, const qpid::types::Variant& v)
{
    result =  v.asInt32();
}

inline void copy(bool& result, const qpid::types::Variant& v)
{
    result =  v.asBool();
}

inline void copy(mtk::Double& result, const qpid::types::Variant& v)
{
    result =  v.asDouble();
}


template<typename T>
void   copy(mtk::nullable<T>& result, const qpid::types::Variant& v)
{
    T temp(__internal_get_default((T*)0));
    copy(temp, v);
    result = temp;
}


template<typename T>
void  copy (mtk::list<T>& result, const qpid::types::Variant& v)
{
    const qpid::types::Variant::List& l = v.asList();
    std::list<qpid::types::Variant>::const_iterator it = l.begin();
    while (it!= l.end())
    {
        T temp(__internal_get_default((T*)0));
        copy(temp, *it);
        result.push_back(temp);
        ++it;
    }
}



    inline void __internal_add2map (qpid::types::Variant::Map& map, const std::string& a, const std::string& key)
    {
        map[key] = a;
    }

    inline void __internal_add2map (qpid::types::Variant::Map& map, const mtk::FixedNumber& a, const std::string& key)
    {
        map[key] = QPID_DESCOMPOSE_FIXED_NUMBER(a);
    }
    inline void __internal_add2map (qpid::types::Variant::Map& map, const mtk::fnExt& a, const std::string& key)
    {
        map[key] = QPID_DESCOMPOSE_FN_EXT(a);
    }

    inline void __internal_add2map (qpid::types::Variant::Map& map, const mtk::Double& a, const std::string& key)
    {
        map[key] = a.get()._0;
    }


    #define REGISTER_LIST_BASIC_TYPE(__TYPE__)         inline void  __internal_add2map  (qpid::types::Variant::Map& map, const mtk::list<__TYPE__>& l, const std::string& key)            {                qpid::types::Variant::List list;                                mtk::list<__TYPE__>::const_iterator it = l.begin();                while (it != l.end())                {                    list.push_back(*it);                    ++it;                }                                map[key] = list;            }    

    REGISTER_LIST_BASIC_TYPE(std::string)
    
    

    //-----------------------------------------------------
    
    inline void  __internal_add2map  (qpid::types::Variant::Map& map, const mtk::list<mtk::DateTime>& l, const std::string& key)
    {
        qpid::types::Variant::List list;
        
        mtk::list<mtk::DateTime>::const_iterator it = l.begin();
        while (it != l.end())
        {
            list.push_back(double(it->__WARNING_NOT_CALL_IT_internal_use_GetTimeQuantitySerialNumber().WarningDontDoThisGetInternal()));
            ++it;
        }
        
        map[key] = list;
    }
    
    inline void  __internal_add2map  (qpid::types::Variant::Map& map, const mtk::list<mtk::dtTimeQuantity>& l, const std::string& key)
    {
        qpid::types::Variant::List list;
        
        mtk::list<mtk::dtTimeQuantity>::const_iterator it = l.begin();
        while (it != l.end())
        {
            list.push_back(double(it->GetQuantitySerialNumber().WarningDontDoThisGetInternal()));
            ++it;
        }
        
        map[key] = list;
    }
    
    
    inline void  __internal_add2map  (qpid::types::Variant::Map& map, const mtk::list<int32_t>& l, const std::string& key)
    {
        qpid::types::Variant::List list;
        
        mtk::list<int32_t>::const_iterator it = l.begin();
        while (it != l.end())
        {
            list.push_back(*it);
            ++it;
        }
        
        map[key] = list;
    }

    inline void  __internal_add2map  (qpid::types::Variant::Map& map, const mtk::list<int16_t>& l, const std::string& key)
    {
        qpid::types::Variant::List list;
        
        mtk::list<int16_t>::const_iterator it = l.begin();
        while (it != l.end())
        {
            list.push_back(*it);
            ++it;
        }
        
        map[key] = list;
    }

    inline void  __internal_add2map  (qpid::types::Variant::Map& map, const mtk::list<int8_t>& l, const std::string& key)
    {
        qpid::types::Variant::List list;
        
        mtk::list<int8_t>::const_iterator it = l.begin();
        while (it != l.end())
        {
            list.push_back(*it);
            ++it;
        }
        
        map[key] = list;
    }
    
    inline void  __internal_add2map  (qpid::types::Variant::Map& map, const mtk::list<int64_t>& l, const std::string& key)
    {
        qpid::types::Variant::List list;
        
        mtk::list<int64_t>::const_iterator it = l.begin();
        while (it != l.end())
        {
            list.push_back(*it);
            ++it;
        }
        
        map[key] = list;
    }

    inline void  __internal_add2map  (qpid::types::Variant::Map& map, const mtk::list<bool>& l, const std::string& key)
    {
        qpid::types::Variant::List list;
        
        mtk::list<bool>::const_iterator it = l.begin();
        while (it != l.end())
        {
            list.push_back(*it);
            ++it;
        }
        
        map[key] = list;
    }
    
    //  for composed types
    template<typename T>
    void  __internal_add2map  (qpid::types::Variant::Map& map, const mtk::list<T>& l, const std::string& key)
    {
        qpid::types::Variant::List list;
        
        typename mtk::list<T>::const_iterator it = l.begin();
        while (it != l.end())
        {
            qpid::types::Variant::Map m;
            __internal_add2map(m, *it);
            list.push_back(m);
            ++it;
        }
        
        map[key] = list;
    }



    inline void __internal_add2map (qpid::types::Variant::Map& map, const mtk::DateTime& a, const std::string& key)
    {
        map[key] = double(a.__WARNING_NOT_CALL_IT_internal_use_GetTimeQuantitySerialNumber().WarningDontDoThisGetInternal());
    }
    inline void __internal_add2map (qpid::types::Variant::Map& map, const mtk::dtTimeQuantity& a, const std::string& key)
    {
        map[key] = double(a.GetQuantitySerialNumber().WarningDontDoThisGetInternal());
    }

    inline void __internal_add2map (qpid::types::Variant::Map& map, const int32_t& a, const std::string& key)
    {
        map[key] = int32_t(a);
    }

    inline void __internal_add2map (qpid::types::Variant::Map& map, const int16_t& a, const std::string& key)
    {
        map[key] = int16_t(a);
    }

    inline void __internal_add2map (qpid::types::Variant::Map& map, const int8_t& a, const std::string& key)
    {
        map[key] = int8_t(a);
    }
    inline void __internal_add2map (qpid::types::Variant::Map& map, const int64_t& a, const std::string& key)
    {
        map[key] = int64_t(a);
    }
    inline void __internal_add2map (qpid::types::Variant::Map& map, const bool& a, const std::string& key)
    {
        map[key] = bool(a);
    }


    template<typename T>
    void  __internal_add2map  (qpid::types::Variant::Map& map, const mtk::nullable<T>& n, const std::string& key)
    {
        if (n.HasValue())
            __internal_add2map(map, n.Get(), key);
    }

    //  for composed types
    template<typename T>
    void  __internal_add2map(qpid::types::Variant::Map& map, const T& t, const std::string& key)
    {
        qpid::types::Variant::Map m;
        __internal_add2map(m, t);
        map[key] = m;
    }




//========================================================================
//------------------------------------------------------------------------
//  I M P L E M E N T A T I O N
//  internal fordward declarations


sub_question::sub_question (   const std::string&  _question,   const mtk::list<std::string >&  _answers,   const mtk::list<std::string >&  _wrong_options)
    :     question(_question),   answers(_answers),   wrong_options(_wrong_options) 
       
    {  
    }



void  sub_question::check_recomended(void) const
{

}

void sub_question::before_send(void) const
{

}




sub_status::sub_status (   const mtk::DateTime&  _started,   const int&  _repetitions,   const int&  _penalizations,   const int&  _options_per_question,   const int&  _failed,   const bool&  _tildes,   const bool&  _english,   const int&  _pendings)
    :     started(_started),   repetitions(_repetitions),   penalizations(_penalizations),   options_per_question(_options_per_question),   failed(_failed),   tildes(_tildes),   english(_english),   pendings(_pendings) 
       
    {  
    }



void  sub_status::check_recomended(void) const
{

}

void sub_status::before_send(void) const
{

}



    //    generate_class_qpid_variant_in_impl
    
sub_question__qpid_map::sub_question__qpid_map (   const std::string&  _question,   const mtk::list<std::string >&  _answers,   const mtk::list<std::string >&  _wrong_options)
      :  m_static( 
   _question,
   _answers,
   _wrong_options) 
    {  
    }



    //    generate_class_qpid_variant_in_impl
    
sub_status__qpid_map::sub_status__qpid_map (   const mtk::DateTime&  _started,   const int&  _repetitions,   const int&  _penalizations,   const int&  _options_per_question,   const int&  _failed,   const bool&  _tildes,   const bool&  _english,   const int&  _pendings)
      :  m_static( 
   _started,
   _repetitions,
   _penalizations,
   _options_per_question,
   _failed,
   _tildes,
   _english,
   _pendings) 
    {  
    }



std::ostream& operator<< (std::ostream& o, const sub_question & c)
{
    o << "{ "

        << "question:"<<   c.question << "  "        << "answers:"<<   c.answers << "  "        << "wrong_options:"<<   c.wrong_options << "  "
        << " }";
    return o;
};



YAML::Emitter& operator << (YAML::Emitter& o, const sub_question & c)
{
    o << YAML::BeginMap

        << YAML::Key << "question"  << YAML::Value <<   c.question        << YAML::Key << "answers"  << YAML::Value <<   c.answers        << YAML::Key << "wrong_options"  << YAML::Value <<   c.wrong_options
        << YAML::EndMap;
    return o;
};



void  operator >> (const YAML::Node& node, sub_question & c)
{


        node["question"]  >> c.question;
        node["answers"]  >> c.answers;
        node["wrong_options"]  >> c.wrong_options;


};


std::ostream& operator<< (std::ostream& o, const sub_status & c)
{
    o << "{ "

        << "started:"<<   c.started << "  "        << "repetitions:"<< c.repetitions<<"  "        << "penalizations:"<< c.penalizations<<"  "        << "options_per_question:"<< c.options_per_question<<"  "        << "failed:"<< c.failed<<"  "        << "tildes:"<< c.tildes<<"  "        << "english:"<< c.english<<"  "        << "pendings:"<< c.pendings<<"  "
        << " }";
    return o;
};



YAML::Emitter& operator << (YAML::Emitter& o, const sub_status & c)
{
    o << YAML::BeginMap

        << YAML::Key << "started"  << YAML::Value <<   c.started        << YAML::Key << "repetitions"  << YAML::Value << c.repetitions        << YAML::Key << "penalizations"  << YAML::Value << c.penalizations        << YAML::Key << "options_per_question"  << YAML::Value << c.options_per_question        << YAML::Key << "failed"  << YAML::Value << c.failed        << YAML::Key << "tildes"  << YAML::Value << c.tildes        << YAML::Key << "english"  << YAML::Value << c.english        << YAML::Key << "pendings"  << YAML::Value << c.pendings
        << YAML::EndMap;
    return o;
};



void  operator >> (const YAML::Node& node, sub_status & c)
{


        node["started"]  >> c.started;
        node["repetitions"]  >> c.repetitions;
        node["penalizations"]  >> c.penalizations;
        node["options_per_question"]  >> c.options_per_question;
        node["failed"]  >> c.failed;
        node["tildes"]  >> c.tildes;
        node["english"]  >> c.english;
        node["pendings"]  >> c.pendings;


};


bool operator== (const sub_question& a, const sub_question& b)
{
    return (          a.question ==  b.question  &&          a.answers ==  b.answers  &&          a.wrong_options ==  b.wrong_options  &&   true  );
};

bool operator!= (const sub_question& a, const sub_question& b)
{
    return !(a==b);
};



bool operator== (const sub_status& a, const sub_status& b)
{
    return (          a.started ==  b.started  &&          a.repetitions ==  b.repetitions  &&          a.penalizations ==  b.penalizations  &&          a.options_per_question ==  b.options_per_question  &&          a.failed ==  b.failed  &&          a.tildes ==  b.tildes  &&          a.english ==  b.english  &&          a.pendings ==  b.pendings  &&   true  );
};

bool operator!= (const sub_status& a, const sub_status& b)
{
    return !(a==b);
};




void  copy (sub_question& c, const qpid::types::Variant& v)
    {
        qpid::types::Variant::Map  mv = v.asMap();

        std::map<qpid::types::Variant::Map::key_type, qpid::types::Variant>::const_iterator it;
//   field_type

                    it = mv.find("q");
                    if (it== mv.end())
                        throw mtk::Alarm(MTK_HERE, "msg_build", "missing mandatory field question on message sub_question::__internal_qpid_fill", mtk::alPriorCritic);
                    else
                        copy(c.question, it->second);
                        //c.question = it->second;
//   field_type

                    it = mv.find("a");
                    if (it== mv.end())
                        throw mtk::Alarm(MTK_HERE, "msg_build", "missing mandatory field answers on message sub_question::__internal_qpid_fill", mtk::alPriorCritic);
                    else
                        copy(c.answers, it->second);
                        //c.answers = it->second;
//   field_type

                    it = mv.find("o");
                    if (it== mv.end())
                        throw mtk::Alarm(MTK_HERE, "msg_build", "missing mandatory field wrong_options on message sub_question::__internal_qpid_fill", mtk::alPriorCritic);
                    else
                        copy(c.wrong_options, it->second);
                        //c.wrong_options = it->second;

        c.check_recomended ();
    }


void  copy (sub_question__qpid_map& c, const qpid::types::Variant& v)
    {
        copy(c.m_static, v);
        c.m_qpid_map = v.asMap();
    }

void __internal_add2map (qpid::types::Variant::Map& map, const sub_question& a)
{

    a.before_send();
    a.check_recomended();

//  field_type
        __internal_add2map(map, a.question, std::string("q"));
//  field_type
        __internal_add2map(map, a.answers, std::string("a"));
//  field_type
        __internal_add2map(map, a.wrong_options, std::string("o"));


};


void __internal_add2map (qpid::types::Variant::Map& map, const sub_question__qpid_map& a)
{
    a.m_static.before_send();
    a.m_static.check_recomended();

    __internal_add2map(map, a.m_static);
    mtk::merge__keep_destination(map, a.m_qpid_map);
};


void __internal_add2map (qpid::types::Variant::Map& map, const mtk::nullable<sub_question>& a, const std::string& field)
{
    if(a.HasValue())
        __internal_add2map(map, a.Get(), field);
}

void __internal_add2map (qpid::types::Variant::Map& map, const mtk::nullable<sub_question__qpid_map>& a, const std::string& field)
{
    if(a.HasValue())
        __internal_add2map(map, a.Get(), field);
}





void  copy (sub_status& c, const qpid::types::Variant& v)
    {
        qpid::types::Variant::Map  mv = v.asMap();

        std::map<qpid::types::Variant::Map::key_type, qpid::types::Variant>::const_iterator it;
//   field_type

                    it = mv.find("s");
                    if (it== mv.end())
                        throw mtk::Alarm(MTK_HERE, "msg_build", "missing mandatory field started on message sub_status::__internal_qpid_fill", mtk::alPriorCritic);
                    else
                        copy(c.started, it->second);
                        //c.started = it->second;
//   sub_msg_type

                    it = mv.find("r");
                    if (it== mv.end())
                        throw mtk::Alarm(MTK_HERE, "msg_build", "missing mandatory field repetitions on message sub_status::__internal_qpid_fill", mtk::alPriorCritic);
                    else
                        copy(c.repetitions, it->second);
                        //__internal_qpid_fill(c.repetitions, it->second.asMap());
//   sub_msg_type

                    it = mv.find("p");
                    if (it== mv.end())
                        throw mtk::Alarm(MTK_HERE, "msg_build", "missing mandatory field penalizations on message sub_status::__internal_qpid_fill", mtk::alPriorCritic);
                    else
                        copy(c.penalizations, it->second);
                        //__internal_qpid_fill(c.penalizations, it->second.asMap());
//   sub_msg_type

                    it = mv.find("opq");
                    if (it== mv.end())
                        throw mtk::Alarm(MTK_HERE, "msg_build", "missing mandatory field options_per_question on message sub_status::__internal_qpid_fill", mtk::alPriorCritic);
                    else
                        copy(c.options_per_question, it->second);
                        //__internal_qpid_fill(c.options_per_question, it->second.asMap());
//   sub_msg_type

                    it = mv.find("f");
                    if (it== mv.end())
                        throw mtk::Alarm(MTK_HERE, "msg_build", "missing mandatory field failed on message sub_status::__internal_qpid_fill", mtk::alPriorCritic);
                    else
                        copy(c.failed, it->second);
                        //__internal_qpid_fill(c.failed, it->second.asMap());
//   sub_msg_type

                    it = mv.find("t");
                    if (it== mv.end())
                        throw mtk::Alarm(MTK_HERE, "msg_build", "missing mandatory field tildes on message sub_status::__internal_qpid_fill", mtk::alPriorCritic);
                    else
                        copy(c.tildes, it->second);
                        //__internal_qpid_fill(c.tildes, it->second.asMap());
//   sub_msg_type

                    it = mv.find("e");
                    if (it== mv.end())
                        throw mtk::Alarm(MTK_HERE, "msg_build", "missing mandatory field english on message sub_status::__internal_qpid_fill", mtk::alPriorCritic);
                    else
                        copy(c.english, it->second);
                        //__internal_qpid_fill(c.english, it->second.asMap());
//   sub_msg_type

                    it = mv.find("p");
                    if (it== mv.end())
                        throw mtk::Alarm(MTK_HERE, "msg_build", "missing mandatory field pendings on message sub_status::__internal_qpid_fill", mtk::alPriorCritic);
                    else
                        copy(c.pendings, it->second);
                        //__internal_qpid_fill(c.pendings, it->second.asMap());

        c.check_recomended ();
    }


void  copy (sub_status__qpid_map& c, const qpid::types::Variant& v)
    {
        copy(c.m_static, v);
        c.m_qpid_map = v.asMap();
    }

void __internal_add2map (qpid::types::Variant::Map& map, const sub_status& a)
{

    a.before_send();
    a.check_recomended();

//  field_type
        __internal_add2map(map, a.started, std::string("s"));
//  sub_msg_type
        __internal_add2map(map, a.repetitions, std::string("r"));
//  sub_msg_type
        __internal_add2map(map, a.penalizations, std::string("p"));
//  sub_msg_type
        __internal_add2map(map, a.options_per_question, std::string("opq"));
//  sub_msg_type
        __internal_add2map(map, a.failed, std::string("f"));
//  sub_msg_type
        __internal_add2map(map, a.tildes, std::string("t"));
//  sub_msg_type
        __internal_add2map(map, a.english, std::string("e"));
//  sub_msg_type
        __internal_add2map(map, a.pendings, std::string("p"));


};


void __internal_add2map (qpid::types::Variant::Map& map, const sub_status__qpid_map& a)
{
    a.m_static.before_send();
    a.m_static.check_recomended();

    __internal_add2map(map, a.m_static);
    mtk::merge__keep_destination(map, a.m_qpid_map);
};


void __internal_add2map (qpid::types::Variant::Map& map, const mtk::nullable<sub_status>& a, const std::string& field)
{
    if(a.HasValue())
        __internal_add2map(map, a.Get(), field);
}

void __internal_add2map (qpid::types::Variant::Map& map, const mtk::nullable<sub_status__qpid_map>& a, const std::string& field)
{
    if(a.HasValue())
        __internal_add2map(map, a.Get(), field);
}



//generate_qpid_coding___coded_as_qpid_Map(class_name, class_info, class_properties, send_code)
//generate_qpid_coding___coded_as_qpid_Map(class_name, class_info, class_properties, send_code)

    sub_question  __internal_get_default(sub_question*)
    {
        return sub_question(
//   field_type
   __internal_get_default ((std::string*)0),
//   field_type
   __internal_get_default ((mtk::list<std::string >*)0),
//   field_type
   __internal_get_default ((mtk::list<std::string >*)0)
            );
    }
    
    sub_status  __internal_get_default(sub_status*)
    {
        return sub_status(
//   field_type
   __internal_get_default ((mtk::DateTime*)0),
//   sub_msg_type
   __internal_get_default((int*)0),
//   sub_msg_type
   __internal_get_default((int*)0),
//   sub_msg_type
   __internal_get_default((int*)0),
//   sub_msg_type
   __internal_get_default((int*)0),
//   sub_msg_type
   __internal_get_default((bool*)0),
//   sub_msg_type
   __internal_get_default((bool*)0),
//   sub_msg_type
   __internal_get_default((int*)0)
            );
    }
    
sub_question::sub_question (const qpid::types::Variant::Map&  mv)
     : //   field_type
   question(__internal_get_default((std::string*)0)),
//   field_type
   answers(__internal_get_default((mtk::list<std::string >*)0)),
//   field_type
   wrong_options(__internal_get_default((mtk::list<std::string >*)0)) 
    {
        copy(*this, mv);
        check_recomended ();  
    }


sub_question__qpid_map::sub_question__qpid_map (const qpid::types::Variant::Map&  mv)
    :  m_static(mv), m_qpid_map(mv)
    {
    }
    

sub_status::sub_status (const qpid::types::Variant::Map&  mv)
     : //   field_type
   started(__internal_get_default((mtk::DateTime*)0)),
//   sub_msg_type
   repetitions(__internal_get_default((int*)0)),
//   sub_msg_type
   penalizations(__internal_get_default((int*)0)),
//   sub_msg_type
   options_per_question(__internal_get_default((int*)0)),
//   sub_msg_type
   failed(__internal_get_default((int*)0)),
//   sub_msg_type
   tildes(__internal_get_default((bool*)0)),
//   sub_msg_type
   english(__internal_get_default((bool*)0)),
//   sub_msg_type
   pendings(__internal_get_default((int*)0)) 
    {
        copy(*this, mv);
        check_recomended ();  
    }


sub_status__qpid_map::sub_status__qpid_map (const qpid::types::Variant::Map&  mv)
    :  m_static(mv), m_qpid_map(mv)
    {
    }
    


};   //namespace ort {
};   //namespace msg {


