#ifndef __HELPERS_H__
#define __HELPERS_H__

#define NEW(type)                       type##_new()
#define INIT(type,object)               type##_init(object)

// sf stands for speed factor
#define UPDATE(object,sf)               object->update(object,sf); 
#define DELETE(object)                  object->delete(object);


#define INIT_SUPER(super,object)        super##_init(object->parent)
#define UPDATE_SUPER(super,object,sf)   super##_update(object->parent,sf)



#define FREE(object)            \
    if (object)                 \
        free(object);           \
    else                        \
        fprintf(stderr, "%s : %d :: Tried to free null ptr\n", __FILE__, __LINE__)



#define IN_RANGE_INC(x,min,max) (x >  min && x <  max)
#define IN_RANGE_EXC(x,min,max) (x >= min && x <= max)

#endif /* __HELPERS_H__ */

