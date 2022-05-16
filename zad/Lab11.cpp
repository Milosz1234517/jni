#include "Lab11.h"
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include<windows.h>

using namespace std;


JNIEXPORT jobjectArray JNICALL Java_Lab11_sort01
  (JNIEnv *env, jobject obj, jobjectArray arr, jobject ord){
	
	jsize len = env->GetArrayLength(arr);

	double *tab = new double[len];

	jclass cDouble = env->FindClass("java/lang/Double");
	jclass cBool = env->FindClass("java/lang/Boolean");

	for(int i = 0; i < len; i++){
		jobject objDouble = env->GetObjectArrayElement(arr, i);
		jmethodID doubleValue = env->GetMethodID(cDouble, "doubleValue", "()D");
		tab[i] = env->CallDoubleMethod(objDouble, doubleValue);
	}

	jmethodID boolValue = env->GetMethodID(cBool, "booleanValue", "()Z");

	bool order = env->CallBooleanMethod(ord, boolValue);

	if(order) sort(tab, tab + len);
	else sort(tab, tab + len, greater<>());

	jmethodID cid = env->GetMethodID(cDouble, "<init>", "(D)V");

	for(int i = 0; i < len; i++){
		jobject result = env->NewObject(cDouble, cid, tab[i]);
		env->SetObjectArrayElement(arr, i, result);
	}

	return arr;
  }

  JNIEXPORT jobjectArray JNICALL Java_Lab11_sort02
  (JNIEnv *env, jobject obj, jobjectArray arr){

		jclass lab11 = env->GetObjectClass(obj);
		jfieldID orderField = env->GetFieldID(lab11, "order", "Ljava/lang/Boolean;");
		jobject ord = env->GetObjectField(obj, orderField);

		jclass cBool = env->FindClass("java/lang/Boolean");
		jmethodID boolValue = env->GetMethodID(cBool, "booleanValue", "()Z");
		bool order = env->CallBooleanMethod(ord, boolValue);

		jsize len = env->GetArrayLength(arr);

		double *tab = new double[len];

		jclass cDouble = env->FindClass("java/lang/Double");

		for(int i = 0; i < len; i++){
			jobject objDouble = env->GetObjectArrayElement(arr, i);
			jmethodID doubleValue = env->GetMethodID(cDouble, "doubleValue", "()D");
			tab[i] = env->CallDoubleMethod(objDouble, doubleValue);
		}

		if(order) sort(tab, tab + len);
		else sort(tab, tab + len, greater<>());

		jmethodID cid = env->GetMethodID(cDouble, "<init>", "(D)V");

		for(int i = 0; i < len; i++){
			jobject result = env->NewObject(cDouble, cid, tab[i]);
			env->SetObjectArrayElement(arr, i, result);
		}

		return arr;
  }

  JNIEXPORT void JNICALL Java_Lab11_sort03
  (JNIEnv *env, jobject obj){

		jclass lab11 = env->GetObjectClass(obj);

		jfieldID aField = env->GetFieldID(lab11, "a", "[Ljava/lang/Double;");
		jfieldID orderField = env->GetFieldID(lab11, "order", "Ljava/lang/Boolean;");

		jobject atab = env->GetObjectField(obj, aField);

		jobjectArray arr = static_cast<jobjectArray>(atab);

		jsize len = env->GetArrayLength(arr);

		jclass cDouble = env->FindClass("java/lang/Double");
		jmethodID cid = env->GetMethodID(cDouble, "<init>", "(D)V");

		jclass cBoolean = env->FindClass("java/lang/Boolean");
		jmethodID cidB = env->GetMethodID(cBoolean, "<init>", "(Z)V");

		double *tab = new double[len];

		cout<<"Podaj elementy:\n";

		for(int i = 0; i < len; i++){
			double val;
			cin >> val;
			tab[i] = val;
		}

		cout<<"Podaj typ sortowania:\n";
		bool ord;
		cin >> ord;

		for(int i = 0; i < len; i++){
			jobject result = env->NewObject(cDouble, cid, tab[i]);
			env->SetObjectArrayElement(arr, i, result);
		}
		
		jobject resultBool = env->NewObject(cBoolean, cidB, ord);
		env->SetObjectField(obj, orderField, resultBool);

		jmethodID mid = env->GetMethodID(lab11, "sort04", "()V");
		env->CallVoidMethod(obj, mid);
  }