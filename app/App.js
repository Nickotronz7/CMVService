import React, { useState, useEffect } from "react";
import { Button, Image, View, Platform, Text } from "react-native";
import * as ImagePicker from "expo-image-picker";
import Constants from "expo-constants";
import CheckBox from "@react-native-community/checkbox";

export default function ImagePickerExample() {
  const [image, setImage] = useState(null);
  const [toggleCheckBox, setToggleCheckBox] = useState(false);
  const [toggleCheckBox1, setToggleCheckBox1] = useState(false);
  const [isSelected, setisSelected] = useState(false);
  var [kl, setKl] = useState("");
  useEffect(() => {
    (async () => {
      if (Platform.OS !== "web") {
        const {
          status,
        } = await ImagePicker.requestMediaLibraryPermissionsAsync();
        if (status !== "granted") {
          alert("Sorry, we need camera roll permissions to make this work!");
        }
      }
    })();
  }, []);

  const SendJson = async () => {
    try {
      await fetch(
        "https://68d66081-c7b9-4a6f-af88-1f187bb3e75c.mock.pstmn.io",
        {
          method: "post",
          mode: "no-cors",
          headers: { "Content-Type": "application/json" },
          body: JSON.stringify({
            operation: toggleCheckBox ? 1 : 0,
            imagen: kl,
          }),
        }
      );
    } catch (e) {
      console.log(e);
    }
  };

  const toDataURL = (url) =>
    fetch(url)
      .then((response) => response.blob())
      .then(
        (blob) =>
          new Promise((resolve, reject) => {
            const reader = new FileReader();
            reader.onloadend = () => resolve(reader.result);
            reader.onerror = reject;
            reader.readAsDataURL(blob);
          })
      );

  const pickImage = async () => {
    let result = await ImagePicker.launchImageLibraryAsync({
      mediaTypes: ImagePicker.MediaTypeOptions.All,
      allowsEditing: true,
      aspect: [4, 3],
      quality: 1,
    });

    setisSelected(true);
    console.log(result);
    toDataURL(result.uri).then((imagen64) => {
      setKl(imagen64);
    });
    if (!result.cancelled) {
      setImage(result.uri);
    }
  };

  return (
    <View style={{ flex: 1, alignItems: "center", justifyContent: "center" }}>
      <Button
        title="Elija la foto que desea procesar "
        color="coral"
        onPress={pickImage}
      />

      {image && (
        <Image source={{ uri: image }} style={{ width: 200, height: 200 }} />
      )}
      <View
        style={{
          flex: 0.25,
          alignItems: "center",
          justifyContent: "center",
          flexDirection: "row",
        }}
      >
        <Text>{isSelected ? "Histograma    Color" : ""}</Text>
      </View>
      <View
        style={{
          flex: 0.25,
          alignItems: "center",
          justifyContent: "center",
          flexDirection: "row",
        }}
      >
        <CheckBox
          disabled={!isSelected}
          value={toggleCheckBox}
          onValueChange={(newValue) => setToggleCheckBox(newValue)}
        />
        <View></View>
        <CheckBox
          disabled={!isSelected}
          value={toggleCheckBox1}
          onValueChange={(newValue) => setToggleCheckBox1(newValue)}
        />
      </View>
      <Button
        title="Enviar"
        onPress={SendJson}
        color="coral"
        disabled={
          !isSelected ||
          (toggleCheckBox && toggleCheckBox1) ||
          (!toggleCheckBox && !toggleCheckBox1)
        }
      />
    </View>
  );
}
