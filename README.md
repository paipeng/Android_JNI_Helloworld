# Android_JNI_Helloworld
A setup project with Android Studio for using NDK



## Create an Android Project

Add ndk dir:

ndk.dir=/pathTo/Android/ndk

## Add a JNI folder by using Android Studio template
Right mouse click on project name(app)->new->Folder->JNI Folder

## Add a native JNI function in MainActivity
private native String jniHelloWorld();


## Generate C ++ header by using javah
cd projectPath/app/src/main

javah -d jni -cp pathTo/Library/Android/sdk/platforms/android-22/android.jar:../../build/intermediates/classes/debug/ com.paipeng.jnihelloworld.MainActivity

(under MAC OS X, the seperator is ':', under Windows it is ';')

## Create a C++ file with the auto generated function

    JNIEXPORT jstring JNICALL Java_com_paipeng_jnihelloworld_MainActivity_jniHelloWorld(JNIEnv *env, jobject thisObj)  {
      //return (*env)->NEWStringUTF(env, "HelloWorld from JNI"); // c
      return (env)->NewStringUTF("Hello from JNI !"); // c++
    }

## Add setting for NDK in gradle, adding the following code into "android -> defaultConfig"
        
        ndk {
            moduleName "moduleHelloWorld"
        }

## Load module in JAVA, add the following code into MainActivity Java class:
    static {
        System.loadLibrary("moduleHelloWorld");
    }

## Call JNI function
        TextView jniTextView = (TextView) findViewById(R.id.jniTextView);
        if (jniTextView != null) {
            jniTextView.setText(jniHelloWorld());
        }
