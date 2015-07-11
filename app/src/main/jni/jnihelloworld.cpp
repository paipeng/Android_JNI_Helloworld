#include "com_paipeng_jnihelloworld_MainActivity.h"

JNIEXPORT jstring JNICALL Java_com_paipeng_jnihelloworld_MainActivity_jniHelloWorld
  (JNIEnv *env, jobject thisObj) {
    //return (*env)->NEWStringUTF(env, "HelloWorld from JNI");
    return (env)->NewStringUTF("Hello from JNI !");
  }